/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/27 20:44:35 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handler(int	hand)
{
	if (hand == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	built(t_cmd *cmd, t_redicio* redic)
{

	if (cmd->pathcmd)
	{
		if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
		{
			ft_pwd(cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->pathcmd, "/bin/echo", ft_strlen(cmd->pathcmd)))
		{
			ft_echo(cmd->cmdarg, cmd->env);
			return ;
		}
		else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/cd", ft_strlen(cmd->pathcmd)))
		{
			ft_cd(cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/env", ft_strlen(cmd->pathcmd)))
		{
			ft_env(cmd);
			return ;
		}
	}
	else
	{
		if (!ft_strncmp(cmd->cmdarg[0], "export", ft_strlen(cmd->cmdarg[0])))
		{
			ft_export(cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->cmdarg[0], "unset", ft_strlen(cmd->cmdarg[0])))
		{
			ft_unset(cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->cmdarg[0], "exit", ft_strlen(cmd->cmdarg[0])))
		{
			write(1, "exit\n", 6);
			exit(0);
		}
	}
	if (cmd != NULL && redic != NULL)
		exec_redic(redic, cmd);
	else
		exec_cmd(cmd);
}