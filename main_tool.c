/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:36:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/22 22:10:49 by ababouel         ###   ########.fr       */
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

char	**dup_env(char **env)
{
	char	**temp_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	temp_env = malloc(sizeof(char *) * (i + 1));
	if (!temp_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		temp_env[i] = ft_strdup(env[i]);
		i++;
	}
	temp_env[i] = NULL;
	return (temp_env);
}

static int	check_dollar(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	delete_var(t_lsnode *lstok, char **env)
{
	t_token	*temp;
	int		check;
	char	*val;

	val = NULL;
	temp = lstok->head;
	while (temp)
	{
		check = ft_filter_token2(temp->value);
		if (check == -1)
			return (0);
		if (check_dollar(temp->value))
		{
			val = temp->value;
			temp->value = search_var(temp->value, env, check);
			if (temp->type == TOKEN_EXP
				|| temp->type == TOKEN_DRINPUT
				|| temp->type == TOKEN_RINPUT
				|| temp->type == TOKEN_ROUTPUT
				|| temp->type == TOKEN_DROUTPUT)
				free(val);
		}
		temp = temp->next;
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
