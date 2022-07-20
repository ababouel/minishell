/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:11:22 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/20 18:43:59 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	*return_new(char *new, char **env, int i, int j)
{
	int	len;

	len = 0;
	new = malloc(sizeof(char) * ft_strlen(env[i]));
	if (!new)
		return (NULL);
	while (env[i][j])
	{
		new[len] = env[i][++j];
		len++;
	}
	return (new);
}

char	*search_in_env(char **env, char *var)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	len = 0;
	new = NULL;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (!ft_strncmp(env[i], var, j)
			&& !ft_isalpha(var[j]) && !ft_isdigit(var[j]))
		{
			new = return_new(new, env, i, j);
			free (var);
			return (new);
		}
		i++;
	}
	free (var);
	return (NULL);
}
