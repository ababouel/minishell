/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:47:35 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/19 17:22:07 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	error_unset(t_cmd *cmd, int i)
{
	if (ft_isalpha(cmd->cmdarg[i][0]) || cmd->cmdarg[i][0] == '_')
		return (0);
	else
	{
		printf("unset: `%s': not a valid identifier\n", cmd->cmdarg[i]);
		return (1);
	}
}

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

int	ft_unset(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->cmdarg[i])
	{
		if (error_unset(cmd, i))
			return (1);
		check_unset(cmd, i);
		i++;
	}
	return (0);
}
