/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:41:51 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/19 17:14:54 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	**equal_export(t_cmd *cmd, int i, int j)
{
	int	len;
	int	size;

	size = 0;
	while (cmd->env[size])
	{
		len = 0;
		while (cmd->env[size][len] && cmd->env[size][len] != '=')
			len++;
		if (!ft_strncmp(cmd->env[size], cmd->cmdarg[i], len) && len == j
			&& !ft_strncmp(cmd->export[size], cmd->cmdarg[i], len))
		{
			cmd->env[size] = cmd->cmdarg[i];
			cmd->export[size] = cmd->cmdarg[i];
			return (cmd->env);
		}
		size++;
	}
	cmd->env[size] = cmd->cmdarg[i];
	cmd->env[++size] = NULL;
	return (cmd->env);
}

char	**plus1_export(t_cmd *cmd, int i, int size)
{
	int	j;

	j = 0;
	while (cmd->cmdarg[i][j])
	{
		if (cmd->cmdarg[i][j] == '+')
		{
			while (cmd->cmdarg[i][j])
			{
				cmd->cmdarg[i][j] = cmd->cmdarg[i][j + 1];
				j++;
			}
			cmd->cmdarg[i][j] = '\0';
			break ;
		}
		j++;
	}
	cmd->env[size] = cmd->cmdarg[i];
	cmd->env[++size] = NULL;
	return (cmd->env);
}

char	**plus_export(t_cmd *cmd, int i, int j)
{
	int	len;
	int	l;
	int	size;
	int	check;

	len = 0;
	size = 0;
	l = 0;
	check = 1;
	while (cmd->env[size])
	{
		while (cmd->env[size][len] && cmd->env[size][len] != '=')
			len++;
		if (!ft_strncmp(cmd->env[size], cmd->cmdarg[i], j) && len == j
			&& !ft_strncmp(cmd->export[size], cmd->cmdarg[i], len))
		{
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
			l = 0;
			++j;
			while (cmd->env[size][l])
				l++;
			while (cmd->cmdarg[i][++j])
			{
				cmd->env[size][l] = cmd->cmdarg[i][j];
				cmd->export[size][l++] = cmd->cmdarg[i][j];
			}
			cmd->env[size][l] = '\0';
			cmd->export[size][l] = '\0';
			return (cmd->env);
		}
		size++;
		len = 0;
	}
	return (plus1_export(cmd, i, size));
}

char	**check_export(t_cmd *cmd, int i, int j)
{
	int	l;
	int	check;

	l = 0;
	check = 0;
	while (cmd->cmdarg[i][j])
	{
		if ((cmd->cmdarg[i][j] == '='
			|| (cmd->cmdarg[i][j] == '+' && cmd->cmdarg[i][j + 1] == '=')) && check == 0)
		{
			if (cmd->cmdarg[i][j] == '+')
				return (plus_export(cmd, i, j));
			else
				return (equal_export(cmd, i, j));
		}
		if (!ft_isalpha(cmd->cmdarg[i][j]) && cmd->cmdarg[i][j] != '_'
			&& !ft_isdigit(cmd->cmdarg[i][j]))
			check = 1;
		j++;
	}
	if (cmd->cmdarg[i][j] != '+' && check == 1)
		return (printf("export: `%s': not a valid identifier\n",
				cmd->cmdarg[i]), cmd->env);
	else
	{
		j = 0;
		while (cmd->cmdarg[i][j])
			j++;
		while (cmd->export[l])
		{
			if (!ft_strncmp(cmd->export[l], cmd->cmdarg[i], j))
				return (cmd->env);
			l++;
		}
		cmd->export[l] = cmd->cmdarg[i];
		cmd->export[++l] = NULL;
		return (cmd->env);
	}
}

int	ft_export(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 1;
	if (!cmd->cmdarg[i])
	{
		sort_export(cmd);
		return (0);
	}
	while (cmd->cmdarg[i])
	{
		if (ft_isalpha(cmd->cmdarg[i][0]) || cmd->cmdarg[i][0] == '_')
		{
			if (!(cmd->cmdarg[i][0] == '_' && cmd->cmdarg[i][1] == '='))
			{
				j = 0;
				cmd->env = check_export(cmd, i, j);
			}
		}
		else
		{
			printf("export: `%s': not a valid identifier\n", cmd->cmdarg[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
