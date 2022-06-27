/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/27 02:47:04 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_pwd(t_cmd *cmd)
{
	char	str[100];

	if(cmd->cmdarg[1])
	{
		if (cmd->cmdarg[1][0] == '-')
		{
			if(cmd->cmdarg[1][1] == '-')
			{
				if(cmd->cmdarg[1][2])
				{
					printf("%c%c: invalid option\n", cmd->cmdarg[1][0], cmd->cmdarg[1][1]);
					return ;
				}
			}
			else if (cmd->cmdarg[1][1])
			{
				printf("%c%c: invalid option\n", cmd->cmdarg[1][0], cmd->cmdarg[1][1]);
				return ;
			}
		}
	}
	if (getcwd(str, sizeof(str)) != NULL)
		printf("%s\n", str);
}

void	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmdarg[1])
	{
		printf("env: %s: No such file or directory\n", cmd->cmdarg[1]);
		return ;
	}
	while (cmd->env[i])
		printf("%s\n", cmd->env[i++]);
}
