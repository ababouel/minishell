/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/26 18:10:53 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	*search_in_env(char **env, char *var)
{
	int	i;
	int	j;
	int	len;
	char	*new;

	i = 0;
	len = 0;
	new = malloc(sizeof(char) * 1000);
	if (!new)
		return (NULL);
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (!ft_strncmp(env[i], var, j))
		{
			while (env[i][j])
			{
				new[len] = env[i][++j];
				len++;
			}
			// printf("%s\n", new);
			return (new);
		}
		i++;
	}
	return (NULL);
}

char	*search_var(char *cmd, char **env)
{
	int	i;
	char	var[1000];

	i = 0;
	if(cmd[0] == '$')
	{
		while (cmd[i])
		{
			if (cmd[i + 1] == 0)
			{
				var[i] = 0;
				break ;
			}
			var[i] = cmd[i + 1];
			i++;
		}
		// printf("%s\n", var);
		return(search_in_env(env, var));
	}
	return (NULL);
}