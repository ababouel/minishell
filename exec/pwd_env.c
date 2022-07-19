/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/19 17:10:00 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	ft_pwd(t_cmd *cmd)
{
	char	str[1000];

	if (cmd->cmdarg[1])
	{
		if (cmd->cmdarg[1][0] == '-')
		{
			if (cmd->cmdarg[1][1] == '-')
			{
				if (cmd->cmdarg[1][2])
				{
					printf("%c%c: invalid option\n",
						cmd->cmdarg[1][0], cmd->cmdarg[1][1]);
					return (1);
				}
			}
			else if (cmd->cmdarg[1][1])
			{
				printf("%c%c: invalid option\n",
					cmd->cmdarg[1][0], cmd->cmdarg[1][1]);
				return (1);
			}
		}
	}
	if (getcwd(str, sizeof(str)) != NULL)
		printf("%s\n", str);
	return (0);
}

int	ft_env(t_cmd *cmd)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	if (cmd->cmdarg[1])
	{
		printf("env: %s: No such file or directory\n", cmd->cmdarg[1]);
		return (1);
	}
	while (cmd->env[i])
	{
		j = 0;
		check = 0;
		while (cmd->env[i][j])
		{
			if (cmd->env[i][j] == '=')
				check = 1;
			j++;
		}
		if (check == 1)
			printf("%s\n", cmd->env[i]);
		i++;
	}
	return (0);
}
