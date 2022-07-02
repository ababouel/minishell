/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/02 21:40:56 by sismaili         ###   ########.fr       */
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
	new = malloc(sizeof(char) * 1000);
	if (!new)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (var[j])
			j++;
		if (!ft_strncmp(env[i], var, j))
		{
			while (env[i][j])
			{
				new[len] = env[i][++j];
				len++;
			}
			return (new);
		}
		i++;
	}
	return (NULL);
}

char	*var_return(char *cmd, char *var, char *new, char **env, int i)
{
	int	l;

	l = 0;
	i++;
	while (cmd[i] && cmd[i] != '$')
	{
		var[l] = cmd[i];
		l++;
		i++;
	}
	var[l] = '\0';
	var = search_in_env(env, var);
	if (var)
		new = ft_strjoin(new, var);
	else
		return (new);
	if (cmd[i] != '$')
		return (new);
	else
	{
		free (var);
		return (var_return(cmd, var, new, env, i));
	}
}

char	*search_var(char *cmd, char **env)
{
	int		i;
	int		j;
	char	*var;
	char	*new;

	i = 0;
	j = 0;
	var = malloc(sizeof(char) * ft_strlen(cmd) + 1);
	new = malloc(sizeof(char) * ft_strlen(cmd) + 1);
	if (!var || !new)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			new = var_return(cmd, var, new, env, i);
			j += ft_strlen(new);
			i += ft_strlen(new);
		}
		else
			new[j] = cmd[i];
		i++;
		j++;
	}
	free (var);
	return (new);
}
