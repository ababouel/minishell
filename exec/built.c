/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/06 09:18:40 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	handler(int hand)
{
	if (hand == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	path_cmd(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->pathcmd, "/bin/pwd", ft_strlen(cmd->pathcmd)))
		ft_pwd(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/bin/echo", ft_strlen(cmd->pathcmd)))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/cd", ft_strlen(cmd->pathcmd)))
		ft_cd(cmd);
	else if (!ft_strncmp(cmd->pathcmd, "/usr/bin/env", ft_strlen(cmd->pathcmd)))
		ft_env(cmd);
	else
		exec_cmd(cmd);
}

void	arg_cmd(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->cmdarg[0], "export", ft_strlen("export")))
		ft_export(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "unset", ft_strlen("unset")))
		ft_unset(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "exit", ft_strlen("exit")))
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	else
		exec_cmd(cmd);
}

void	built(t_cmd *cmd, int check)
{
	int	i;

	i = 0;
	while (cmd->cmdarg[i])
	{
		cmd->cmdarg[i] = search_var(cmd->cmdarg[i], cmd->env, check);
		i++;
	}
	if (cmd->pathcmd && ft_strcmp(cmd->cmdarg[0], "export")
		&& ft_strcmp(cmd->cmdarg[0], "unset"))
	{
		path_cmd(cmd);
		return ;
	}
	else
	{
		arg_cmd(cmd);
		return ;
	}
	i++;
}
