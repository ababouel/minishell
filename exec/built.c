/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/21 03:58:32 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

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
	if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
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
	redic_open(cmd);
	ft_stat_pipe_dup(data, lsdata);
	if (cmd->pathcmd)
		path_cmd(data);
	else
	{
		printf("%s: command not found\n", cmd->cmdarg[0]);
		g_l.state = 127;
		exit(g_l.state);
	}
}
