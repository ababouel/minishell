/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:47:35 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/28 16:48:02 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	check_unset(t_cmd *cmd, int i)
{
	int	j;

	j = 0;
	while (cmd->env[j])
	{
		if (!ft_strncmp(cmd->cmdarg[i], cmd->env[j], ft_strlen(cmd->cmdarg[i])))
		{
			while (cmd->env[j])
			{
				cmd->env[j] = cmd->env[j + 1];
				j++;
				if (cmd->env[j + 1] == NULL)
				{
					cmd->env[j] = NULL;
					break ;
				}
			}
		}
		else
			j++;
	}
}

void	ft_unset(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->cmdarg[i])
	{
		check_unset(cmd, i);
		i++;
	}
}
