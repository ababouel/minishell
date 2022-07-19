/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:42:14 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/19 16:50:41 by ababouel         ###   ########.fr       */
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

static void	waitprocess(t_data *dt, int len, int *pid)
{
	int	x;
	int	state;

	x = 0;
	state = 0;
	ft_stat_pipe_close(dt);
	while (x < len)
		waitpid(pid[x++], &state, 0);
	if (state == SIGINT)
		printf("\n");
	if (state == SIGQUIT)
		printf("Quit: 3\n");
}

void	execution(t_lsdata *data)
{
	t_data	*dt;
	int		pid[1000];
	int		len;

	len = 0;
	dt = data->head;
	signal(SIGQUIT, handler);
	while (dt != NULL)
	{
		pid[len] = forcked();
		if (pid[len] == 0)
			built(dt, data);
		if (pid[len] > 0)
			redic_close(&dt->cmd);
		if (dt != NULL)
			dt = dt->next;
		len++;
	}
	dt = data->head;
	waitprocess(dt, len, pid);
	signal(SIGQUIT, SIG_IGN);
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
