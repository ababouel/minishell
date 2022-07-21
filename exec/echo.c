/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:44:53 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/21 01:29:09 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	check_echo(t_cmd *cmd, int check, int i)
{
	int	j;

	if (check == 1)
		i++;
	while (cmd->cmdarg[i])
	{
		j = 0;
		while (cmd->cmdarg[i][j])
		{
			if (cmd->cmdarg[i][j] == '$' && cmd->cmdarg[i][j + 1] == '?')
			{
				printf("%d", g_l.state);
				j += 2;
			}
			else
				printf("%c", cmd->cmdarg[i][j++]);
		}
		i++;
		if (cmd->cmdarg[i])
			printf(" ");
	}
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	if (!cmd->cmdarg[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	while (cmd->cmdarg[1][i] && cmd->cmdarg[1][0] == '-')
	{
		if (cmd->cmdarg[1][i] != 'n')
		{
			check = 0;
			break ;
		}
		check = 1;
		i++;
	}
	check_echo(cmd, check, 1);
	if (check == 0)
		printf("\n");
	return (0);
}
