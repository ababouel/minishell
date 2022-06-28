/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:25:59 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/28 19:27:41 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	simple_sort(t_cmd *cmd, int size)
{
	int	step;
	int	i;
	int	temp;

	step = 0;
	while (step < size - 1)
	{
		i = 0;
		while (i < size - step - 1)
		{
			if (cmd->cmdarg[i] > cmd->cmdarg[i])
			{
				temp = cmd->cmdarg[i];
				cmd->cmdarg[i] = cmd->cmdarg[i + 1];
				cmd->cmdarg[i + 1] = temp;
			}
			i++;
		}
		step++;
	}
}
