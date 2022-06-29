/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:58:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/29 10:52:30 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	**bubble_sort(t_cmd *cmd)
{
	int		size;
	int		step;
	int		i;
	int		j;
	char	*temp;

	step = 0;
	size = 0;
	while (cmd->export[size])
		size++;
	while (step < size - 1)
	{
		i = 0;
		while (i < size - step - 1)
		{
			j = 0;
			while (cmd->export[i][j])
			{
				if (cmd->export[i][j] > cmd->export[i + 1][j])
				{
					temp = cmd->export[i];
					cmd->export[i] = cmd->export[i + 1];
					cmd->export[i + 1] = temp;
					break ;
				}
				else if (cmd->export[i][j] == cmd->export[i + 1][j])
					j++;
				else
					break ;
			}
			i++;
		}
		step++;
	}
	return (cmd->export);
}

void    sort_export(t_cmd *cmd)
{
    int i;

    i = 0;
    cmd->export = bubble_sort(cmd);
    while (cmd->export[i])
        printf("declare -x %s\n", cmd->export[i++]);
}