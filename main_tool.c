/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:36:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/25 02:31:32 by sismaili         ###   ########.fr       */
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

static void	sep_tokenlsexp(t_token *temp, t_env *env)
{
	char	*val;

	val = NULL;
	while (temp)
	{
		if (temp->type == TOKEN_SINQTE)
			temp->value = remove_quote(temp->value, '\'');
		else if (temp->type == TOKEN_DQUOTE)
		{
			val = temp->value;
			temp->value = remove_quote(temp->value, '"');
			temp->value = search_var(temp->value, env->head);
		}
		else if (temp->type == TOKEN_DOLLAR || temp->type == TOKEN_EXP)
		{
			val = temp->value;
			temp->value = search_var(temp->value, env->head);
		}
		if (val)
			free(val);
		val = NULL;
		temp = temp->next;
	}
}

static void	join_tokenlsexp(t_token *temp, t_token *head)
{
	while (temp)
	{
		if (head->value == NULL)
		{
			if (temp && temp->value)
				head->value = ft_strdup(temp->value);
			else
				head->value = ft_strdup("");
		}
		else
			head->value = ft_strjoinbis(head->value, temp->value);
		temp = temp->next;
	}
}

int	delete_var(t_lsnode *lstok, t_env *env)
{
	t_token		*head;
	t_lexer		*lexer;
	t_lsnode	lsexp;
	t_token		*temp;

	lexer = NULL;
	temp = NULL;
	head = lstok->head;
	while (head)
	{
		if (head->type == TOKEN_EXP)
		{
			lsexp = *add_init_lsexp(&lsexp, head->value);
			temp = lsexp.head;
			sep_tokenlsexp(temp, env);
			temp = lsexp.head;
			free(head->value);
			head->value = NULL;
			join_tokenlsexp(temp, head);
			ft_freestackbis(&lsexp);
		}
		head = head->next;
	}
	return (1);
}
