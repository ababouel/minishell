/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:36:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/24 19:53:33 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*readline_t(void)
{
	char			*buf;
	struct termios	attr;
	struct termios	old_attr;

	tcgetattr(STDIN_FILENO, &old_attr);
	attr = old_attr;
	attr.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &attr);
	buf = readline("minishell$ ");
	tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &old_attr);
	return (buf);
}

// static int	check_dollar(char *cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == '$')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static t_lsnode	*add_init_lsexp(t_lsnode *lstok, char *line)
{
	t_lexer	*lexer;
	t_token	*token;

	lexer = NULL;
	token = NULL;
	init_stack(lstok);
	lexer = init_lexer(line);
	while (lexer->i < ft_strlen(line))
	{
		if (lexer->src[lexer->i] != '\0')
			token = lexer_cat_token(lexer);
		if (token != NULL)
			ins_next_node(lstok, (void *) token);
	}
	free(lexer);
	lexer = NULL;
	return (lstok);
}

int	delete_var(t_lsnode *lstok, t_env *env)
{
	t_token		*head;
	t_lexer		*lexer;
	t_lsnode	lsexp;
	t_token		*temp;
	char		*val;

	lexer = NULL;
	temp = NULL;
	(void) env;
	val = NULL;
	head = lstok->head;
	while (head)
	{
		if (head->type == TOKEN_EXP)
		{
			lsexp = *add_init_lsexp(&lsexp, head->value);
			temp = lsexp.head;
			while (temp)
			{
				if (temp->type == TOKEN_SINQTE)
					temp->value = remove_quote(temp->value, '\'');
				else if (temp->type == TOKEN_DQUOTE)
				{
					val = temp->value;
					temp->value = remove_quote(temp->value,'"');
					temp->value = search_var(temp->value, env->head);
				}
				else if(temp->type == TOKEN_DOLLAR || temp->type == TOKEN_EXP)
				{
					val = temp->value;
					temp->value = search_var(temp->value, env->head);
				}
				if (val)
					free(val);
				val = NULL;
				temp = temp->next;
			}
			temp = lsexp.head;
			free(head->value);
			head->value = NULL;
			while (temp)
			{
				if (head->value == NULL)
					head->value = ft_strdup(temp->value);
				else
					head->value = ft_strjoinbis(head->value, temp->value);
				temp = temp->next;
			}
			ft_freestackbis(&lsexp);
		}
		head = head->next;
	}
	return (1);
}



t_lsnode	*add_init_lstok(t_lsnode *lstok, char *line)
{
	t_lexer	*lexer;
	t_token	*token;

	lexer = NULL;
	token = NULL;
	init_stack(lstok);
	lexer = init_lexer(line);
	while (lexer->i < ft_strlen(line))
	{
		if (lexer->src[lexer->i] != '\0')
			token = lexer_next_token(lexer);
		if (token != NULL)
			ins_next_node(lstok, (void *) token);
	}
	free(lexer);
	lexer = NULL;
	return (lstok);
}

// int	delete_var(t_lsnode *lstok, t_env *env)
// {
// 	t_token	*temp;
// 	int		check;
// 	char	*val;
// 	t_val	*head;

// 	val = NULL;
// 	temp = lstok->head;
// 	head = env->head;
// 	while (temp)
// 	{
// 		check = ft_filter_token2(temp->value);
// 		if (check == -1)
// 			return (0);
// 		if (check_dollar(temp->value))
// 		{
// 			val = temp->value;
// 			temp->value = search_var(temp->value, head, check);
// 			if (temp->type == TOKEN_EXP
// 				|| temp->type == TOKEN_DRINPUT
// 				|| temp->type == TOKEN_RINPUT
// 				|| temp->type == TOKEN_ROUTPUT
// 				|| temp->type == TOKEN_DROUTPUT)
// 				free(val);
// 		}
// 		temp = temp->next;
// 	}
// 	return (1);
// :w
// }