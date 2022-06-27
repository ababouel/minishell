/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:25:44 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/27 15:27:03 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	check_echo(t_cmd *cmd, int i, int j)
{
	while (cmd->cmdarg[i])
	{
		printf("%s", cmd->cmdarg[i]);
		i++;
		if (i != j)
			printf(" ");
	}
}

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	j = 0;
	check = 0;
	if (!cmd->cmdarg[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (cmd->cmdarg[j])
		j++;
	if (!ft_strncmp(cmd->cmdarg[1], "-n", ft_strlen(cmd->cmdarg[1])))
	{
		i++;
		check = 1;
	}
	check_echo(cmd, i, j);
	if (check == 0)
		printf("\n");
}
