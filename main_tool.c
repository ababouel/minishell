/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:36:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 02:32:39 by ababouel         ###   ########.fr       */
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

static int execbuilt(t_data *dt)
{
    if (!ft_strncmp(dt->cmd.cmdarg[0], "export", ft_strlen("export")))
	{
		g_l.state = ft_export(&dt->cmd);
		return (1);	
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "unset", ft_strlen("unset")))
	{
		g_l.state = ft_unset(&dt->cmd);
		return (1);
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "exit", ft_strlen("exit")))
	{
		write(1, "exit\n", 6);
		exit(0);
    }
	else if (dt->cmd.pathcmd != NULL && !ft_strncmp(dt->cmd.pathcmd, "/usr/bin/env", ft_strlen(dt->cmd.pathcmd)))
	{
		g_l.state = ft_env(&dt->cmd);
		return (1);
	}
	else if (dt->cmd.pathcmd != NULL && !ft_strncmp(dt->cmd.pathcmd, "/usr/bin/cd", ft_strlen(dt->cmd.pathcmd)))
	{
		g_l.state = ft_cd(&dt->cmd);
		return (1);
	}
    return (0);
}

static void	waitprocess(t_data *dt, int len, int *pid)
{
	int	x;
    
    x = 0;
    ft_stat_pipe_close(dt);
	while(x < len)
	{
		waitpid(pid[x++], &g_l.state, 0);
		if (WIFEXITED(g_l.state))
			g_l.state = WEXITSTATUS(g_l.state);
	}
	if (g_l.state == SIGINT)
		printf("\n");
	if (g_l.state == SIGQUIT)
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
    if(execbuilt(dt) == 1)
        return ;
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