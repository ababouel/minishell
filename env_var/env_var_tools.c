/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:11:22 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/23 15:12:31 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*return_new(char *new, char *env, int j)
{
	int	len;

	len = 0;
	new = malloc(sizeof(char) * ft_strlen(env[j]));
	if (!new)
		return (NULL);
	while (env[j])
	{
		new[len] = env[++j];
		len++;
	}
	return (new);
}

char	*search_in_env(t_val *env, char *var)
{
	int		j;
	int		len;
	char	*new;
	t_val	*result;

	i = 0;
	len = 0;
	new = NULL;
	if (var[0] == '?')
	{
		free (var);
		return (ft_itoa(g_l.state));
	}
	result = search_val(env, var);
	if (result && result->value != NULL)
	{
		j = 0;
		while (result->value[j] != '=')
			j++;	
		new = return_new(new, result->value, j);
		free (var);
		return (new);
	}
	free (var);
	return (NULL);
}



// char	*return_new(char *new, char **env, int i, int j)
// {
// 	int	len;

// 	len = 0;
// 	new = malloc(sizeof(char) * ft_strlen(env[i]));
// 	if (!new)
// 		return (NULL);
// 	while (env[i][j])
// 	{
// 		new[len] = env[i][++j];
// 		len++;
// 	}
// 	return (new);
// }

// char	*search_in_env(char **env, char *var)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*new;

// 	i = 0;
// 	len = 0;
// 	new = NULL;
// 	if (var[0] == '?')
// 	{
// 		free (var);
// 		return (ft_itoa(g_l.state));
// 	}
// 	while (env[i])
// 	{
// 		j = 0;
// 		while (env[i][j] != '=')
// 			j++;
// 		if (!ft_strncmp(env[i], var, j)
// 			&& !ft_isalpha(var[j]) && !ft_isdigit(var[j]))
// 		{
// 			new = return_new(new, env, i, j);
// 			free (var);
// 			return (new);
// 		}
// 		i++;
// 	}
// 	free (var);
// 	return (NULL);
// }