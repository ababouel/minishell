/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/04 12:00:47 by sismaili         ###   ########.fr       */
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
			free (var);
			return (new);
		}
		i++;
	}
	free (var);
	return (NULL);
}

// char	*var_return(char *cmd, char *var, char *new, char **env, int i)
// {
// 	int	l;

// 	l = 0;
// 	i++;
// 	while (cmd[i] && cmd[i] != '$')
// 		var[l++] = cmd[i++];
// 	var[l] = '\0';
// 	var = search_in_env(env, var);
// 	if (var)
// 	{
// 		new = ft_strjoin(new, var);
// 		free (var);
// 	}
// 	else
// 		free (var);
// 	return (new);
// }

char	*search_var(char *cmd, char **env)
{
	int		i;
	int		j;
	int		l;
	char	*new;
	char	*var;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(cmd));
	if (!new)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			var = malloc(sizeof(char) * ft_strlen(cmd) + 1);
			if (!var)
				return (NULL);
			l = 0;
			i++;
			while (cmd[i] && cmd[i] != '$' && (ft_isalpha(cmd[i]) || ft_isdigit(cmd[i])))
				var[l++] = cmd[i++];
			var[l] = '\0';
			var = search_in_env(env, var);
			if (var)
			{
				new = ft_strjoin(new, var);
				j = ft_strlen(new);
				free (var);
			}
			else
				free (var);
		}
		else
			new[j++] = cmd[i++];
	}
	return (new);
}
