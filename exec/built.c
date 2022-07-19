/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/19 13:07:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handler(int hand)
{
	if (hand == SIGQUIT && g_v.g_pid == 1)
		return ;
	if (hand == SIGINT && g_v.g_pid == 0)
		exit (2);
	if (hand == SIGQUIT && g_v.g_pid == 0)
		exit (3);
	if (hand == SIGINT && g_v.g_pid == 1)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	check_pathcmd(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
	{
		ft_pwd(cmd);
		exit(0);
	}
	else if (!ft_strncmp(cmd->pathcmd, "/bin/echo", ft_strlen(cmd->pathcmd)))
	{
		ft_echo(cmd->cmdarg, cmd->env);
		exit(0);
	}
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/cd", ft_strlen(cmd->pathcmd)))
	{
		ft_cd(cmd);
		exit(0);
	}
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/env", ft_strlen(cmd->pathcmd)))
	{
		ft_env(cmd);
		exit(0);
	}
}

void	built(t_data *data, t_lsdata *lsdata)
{
	t_cmd	*cmd;

	cmd = &data->cmd;
	ft_stat_pipe_dup(data, lsdata);
	redic_open(cmd);
	if (cmd->pathcmd)
		check_pathcmd(cmd);
	else
	{
		if (!ft_strncmp(cmd->cmdarg[0], "export", ft_strlen(cmd->cmdarg[0])))
		{
			ft_export(cmd);
			exit(0);
		}
		else if (!ft_strncmp(cmd->cmdarg[0], "unset",
				ft_strlen(cmd->cmdarg[0])))
		{
			ft_unset(cmd);
			exit(0);
		}
	}
	exec_pipe(data);
}
