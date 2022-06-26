/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:21:01 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/25 11:20:56 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	handler(int	hand)
{
	if (hand == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		// rl_replace_line();
		rl_redisplay();
	}
}

void	built(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->cmdarg[0], "pwd", ft_strlen(cmd->cmdarg[0])))
		ft_pwd();
	else if (!ft_strncmp(cmd->cmdarg[0], "echo", ft_strlen(cmd->cmdarg[0])))
		ft_echo(cmd->cmdarg);
	else if (!ft_strncmp(cmd->cmdarg[0], "cd", ft_strlen(cmd->cmdarg[0])))
		ft_cd(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "env", ft_strlen(cmd->cmdarg[0])))
		ft_env(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "export", ft_strlen(cmd->cmdarg[0])))
		ft_export(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "unset", ft_strlen(cmd->cmdarg[0])))
		ft_unset(cmd);
	else if (!ft_strncmp(cmd->cmdarg[0], "exit", ft_strlen(cmd->cmdarg[0])))
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	else
		exec_cmd(cmd);
}