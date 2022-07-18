/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/18 20:37:06 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	handler(int	hand)
{
	if (hand == SIGQUIT && gl.g_pid == 1)
		return ;
	if (hand == SIGINT && gl.g_pid == 0)
		exit (2);
	if (hand == SIGQUIT && gl.g_pid == 0)
		exit (3);
	if (hand == SIGINT && gl.g_pid == 1)
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
	if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
		ft_pwd(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/bin/echo", ft_strlen(cmd->pathcmd)))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/cd", ft_strlen(cmd->pathcmd)))
		ft_cd(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/env", ft_strlen(cmd->pathcmd)))
		ft_env(cmd);
	else
		exec_pipe(dt);
	gl.state = 0;
	exit(0);
}

void	arg_cmd(t_data *dt)
{
	t_cmd	*cmd;

	cmd = &dt->cmd;
	if (!ft_strncmp(cmd->cmdarg[0], "exit", ft_strlen("exit")))
	{
		write(1, "exit\n", 6);
		exit(0);
	}
}

void	built(t_data *data, t_lsdata *lsdata)
{
	t_cmd *cmd;
	
	cmd = &data->cmd;
    redic_open(cmd);
    ft_stat_pipe_dup(data, lsdata);
	if (cmd->pathcmd)
	{
		path_cmd(data);
	}
	else
	{
		printf("%s: command not found\n", cmd->cmdarg[0]);
		exit (0);
	}
}
