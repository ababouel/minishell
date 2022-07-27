/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:13:20 by ababouel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 01:12:32 by ababouel         ###   ########.fr       */
=======
/*   Updated: 2022/07/25 21:13:19 by sismaili         ###   ########.fr       */
>>>>>>> 65ed65745d7785e4f61b009c854769cc203fd045
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	builtin_cmdargbis(t_data *data, t_cmd *cmd)
{
	if (!ft_strncmp(data->cmd.cmdarg[0],
			"pwd", ft_strlen(data->cmd.cmdarg[0]))
		&& ft_strlen(data->cmd.cmdarg[0]) == 3)
	{
		g_l.state = ft_pwd();
		exit(g_l.state);
	}
	else if (!ft_strncmp(data->cmd.cmdarg[0],
			"echo", ft_strlen(data->cmd.cmdarg[0]))
		&& ft_strlen(data->cmd.cmdarg[0]) == 4)
	{
		g_l.state = ft_echo(cmd);
		exit(g_l.state);
	}
}

static void	builtin_cmdarg(t_data *data, t_cmd *cmd)
{
	if (data->pipe.statpipe != NUL
		&& !ft_strncmp(data->cmd.cmdarg[0],
			"export", ft_strlen(data->cmd.cmdarg[0]))
		&& ft_strlen(data->cmd.cmdarg[0]) == 6)
	{
		g_l.state = ft_export(cmd);
		exit(g_l.state);
	}
	else if (data->pipe.statpipe != NUL
		&& !ft_strncmp(data->cmd.cmdarg[0],
			"unset", ft_strlen(data->cmd.cmdarg[0]))
		&& ft_strlen(data->cmd.cmdarg[0]) == 5)
	{
		g_l.state = ft_unset(cmd);
		exit(g_l.state);
	}
}

void	handler(int hand)
{
	if (hand == SIGQUIT && g_l.g_pid == 1)
		return ;
	if (hand == SIGINT && g_l.g_pid == 0)
		exit(2);
	if (hand == SIGQUIT && g_l.g_pid == 0)
		exit(3);
	if (hand == SIGINT && g_l.g_pid == 1)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	path_cmd(t_data *dt)
{
	t_cmd	*cmd;

	cmd = &dt->cmd;
	if (!ft_strncmp(cmd->pathcmd, "/usr/bin/env", ft_strlen(cmd->pathcmd)))
		g_l.state = ft_env(&dt->cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
		g_l.state = ft_pwd();
	else if (!ft_strncmp(cmd->pathcmd, "/bin/echo", ft_strlen(cmd->pathcmd)))
		g_l.state = ft_echo(cmd);
	else
		exec_pipe(dt);
	exit(g_l.state);
}

void	built(t_data *data, t_lsdata *lsdata)
{
	t_cmd	*cmd;

	cmd = &data->cmd;
	ft_stat_pipe_dup(data, lsdata);
	redic_open(cmd);
	builtin_cmdarg(data, cmd);
	builtin_cmdargbis(data, cmd);
	if (cmd->pathcmd)
		path_cmd(data);
	else
	{
		if (access(cmd->cmdarg[0], X_OK) == -1)
			g_l.state = 126;
		else
			g_l.state = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->cmdarg[0], 2);
		perror(" ");
		exit(g_l.state);
	}
}
