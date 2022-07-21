/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:40:14 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/19 22:10:27 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**cmdenv2(t_cmd *cmd, int size, int i, int j)
{
	int	l;

	l = ft_strlen(cmd->env[size]);
	++j;
	while (cmd->cmdarg[i][++j])
	{
		cmd->env[size][l] = cmd->cmdarg[i][j];
		cmd->export[size][l++] = cmd->cmdarg[i][j];
	}
	cmd->env[size][l] = '\0';
	cmd->export[size][l] = '\0';
	return (cmd->env);
}

char	**cmdenv(t_cmd *cmd, int i, int j, int size)
{
	int	l;
	int	check;

	l = 0;
	check = 1;
	while (cmd->export[size][l])
	{
		if (cmd->export[size][l] == '=')
			check = 0;
		l++;
	}
	if (check)
	{
		cmd->export[size][l] = '=';
		cmd->export[size][++l] = '\0';
	}
	cmd->env = cmdenv2(cmd, size, i, j);
	return (cmd->env);
}

char	**exportenv(t_cmd *cmd, int i, int j, int check)
{
	int	l;

	l = 0;
	if (cmd->cmdarg[i][j] != '+' && check == 1)
		return (printf("export: `%s': not a valid identifier\n",
				cmd->cmdarg[i]),
			cmd->env);
	else
	{
		j = 0;
		while (cmd->cmdarg[i][j])
			j++;
		while (cmd->export[l])
		{
			if (!ft_strncmp(cmd->export[l], cmd -> cmdarg[i], j))
				return (cmd->env);
			l++;
		}
		cmd->export[l] = cmd->cmdarg[i];
		cmd->export[++l] = NULL;
		return (cmd->env);
	}
}
