/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:41:51 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/27 21:36:31 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	check_export(t_cmd *cmd, int i, int len)
{
	int	j;
	int	size;

	size = 0;
	if (ft_isalpha(cmd->cmdarg[i][0]))
	{
		j = 0;
		while (cmd->cmdarg[i][j])
		{
			if (cmd->cmdarg[i][j] == '=' || (cmd->cmdarg[i][j] == '+' && cmd->cmdarg[i][j + 1] == '='))
			{
				while (cmd->env[size])
				{
					if (!ft_strncmp(cmd->env[size], cmd->cmdarg[i], j))
					{
						cmd->env[size] = cmd->cmdarg[i];
						return ;
					}
					size++;
				}
				if (cmd->cmdarg[i][j] == '+')
				{
					while (cmd->cmdarg[i][j])
					{
						cmd->cmdarg[i][j] = cmd->cmdarg[i][j + 1];
						j++;
					}
					cmd->cmdarg[i][j] = '\0';
				}
				cmd->env[len] = cmd->cmdarg[i];
				cmd->env[++len] = NULL;
			}
			j++;
		}
	}
	else
		perror(cmd->cmdarg[i]);
}

void	ft_export(t_cmd *cmd)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (cmd->env[len])
		len++;
	while (cmd->cmdarg[i])
	{
		check_export(cmd, i, len);
		i++;
		len++;
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
