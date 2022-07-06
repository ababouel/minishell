/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:25:44 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/06 09:54:29 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	check_echo(t_cmd *cmd, int check, int i)
{
	if (check == 1)
		i++;
	while (cmd->cmdarg[i])
	{
		printf("%s", cmd->cmdarg[i]);
		i++;
		if (cmd->cmdarg[i])
			printf(" ");
	}
}

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	j = 1;
	check = 0;
	if (!cmd->cmdarg[1])
	{
		write(1, "\n", 1);
		return ;
	}
	if (cmd->cmdarg[i][0] == '-')
	{
		while (cmd->cmdarg[i][j])
		{
			if (cmd->cmdarg[i][j] != 'n')
			{
				check = 0;
				break ;
			}
			check = 1;
			j++;
		}
	}
	check_echo(cmd, check, i);
	if (check == 0)
		printf("\n");
}
