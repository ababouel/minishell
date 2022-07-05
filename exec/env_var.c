/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/05 16:51:45 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	*search_in_env(char **env, char *var)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	len = 0;
	if (!var)
		return (NULL);
	new = malloc(sizeof(char) * 1000);
	if (!new)
		return (NULL);
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			j = ft_strlen(var);
			while (env[i][j])
			{
				new[len] = env[i][++j];
				len++;
			}
			free (var);
			return (new);
		}
		i++;
	}
	free (var);
	return (NULL);
}

int	check_doll(char *cmd, int i)
{
	int	dollar;

	dollar = 0;
	if (!cmd[i + 1])
		return (0);
	else if (ft_isalpha(cmd[i + 1]) || ft_isdigit(cmd[i + 1]))
		return (1);
	else if (cmd[i + 1] == '$')
	{
		while (cmd[i] == '$')
		{
			dollar += 1;
			i++;
		}
		return (dollar);
	}
	else
		return (0);
}

char	*search_var(char *cmd, char **env)
{
	int		i;
	int		l;
	char	*new;
	char	*var;
	char	*temp;

	i = 0;
	new = ft_strdup("");
	if (!new)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '$' && check_doll(cmd, i) == 1)
		{
			var = malloc(sizeof(char) * ft_strlen(cmd) + 1);
			if (!var)
				return (NULL);
			l = 0;
			i++;
			while (cmd[i] && cmd[i] != '$' && (ft_isalpha(cmd[i]) || ft_isdigit(cmd[i])))
			{
				if (ft_isdigit(cmd[i]) && cmd[i - 1] == '$')
				{
					var[l++] = cmd[i++];
					break ;
				}
				var[l++] = cmd[i++];
			}
			var[l] = '\0';
			var = search_in_env(env, var);
			if (var)
			{
				new = ft_strjoin(new, var);
				free (var);
			}
			else
				free (var);
		}
		else
		{
			printf("test\n");
			temp = malloc(2);
			temp[0] = cmd[i++];
			temp[1] = '\0';
			new = ft_strjoin(new, temp);
			free (temp);
		}
	}
	return (new);
}
