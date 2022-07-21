/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:36:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 16:45:12 by ababouel         ###   ########.fr       */
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