/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_toolbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:42:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 16:47:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execpathcmd(t_data *dt)
{
	if (dt->cmd.pathcmd != NULL)
	{
		if (!ft_strncmp(dt->cmd.pathcmd,
					"/usr/bin/env", ft_strlen(dt->cmd.pathcmd)))
		{
			g_l.state = ft_env(&dt->cmd);
			return (1);
		}
		else if (!ft_strncmp(dt->cmd.pathcmd,
					"/usr/bin/cd", ft_strlen(dt->cmd.pathcmd)))
		{
			g_l.state = ft_cd(&dt->cmd);
			return (1);
		}
	}
	return (0);
}

static int	execbuilt(t_data *dt)
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
	return (0);
}

static void	waitprocess(t_data *dt, int len, int *pid)
{
	int	x;

	x = 0;
	ft_stat_pipe_close(dt);
	while (x < len)
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
	if (execbuilt(dt) == 1)
		return ;
	if (execpathcmd(dt) == 1)
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
