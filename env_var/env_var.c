/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/05 22:39:08 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	check_doll(char *cmd, int i)
{
	if (!cmd[i + 1])
		return (0);
	else if (cmd[i + 1] == '$')
		return (0);
	else if (cmd[i + 1] == '?')
		return (0);
	else
		return (1);
}

char	*join_new(char *new, char *var, char **env, int l)
{
	var[l] = '\0';
	var = search_in_env(env, var);
	if (var)
	{
		new = ft_strjoin(new, var);
		free (var);
	}
	else
		free (var);
	return (new);
}

char	*fill_new(char *new, char *cmd, char **env, int *i)
{
	char	*var;
	int		l;

	var = malloc(sizeof(char) * ft_strlen(cmd) + 1);
	if (!var)
		return (NULL);
	l = 0;
	(*i)++;
	while (cmd[*i] && cmd[*i] != '$'
		&& (ft_isalpha(cmd[*i]) || ft_isdigit(cmd[*i])))
	{
		if (ft_isdigit(cmd[*i]) && cmd[*i - 1] == '$')
		{
			var[l++] = cmd[(*i)++];
			break ;
		}
		var[l++] = cmd[(*i)++];
	}
	new = join_new(new, var, env, l);
	return (new);
}

char	*search_var(char *cmd, char **env, int check)
{
	int		i;
	char	*new;
	char	*temp;

	i = 0;
	new = ft_strdup("");
	if (!new)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\'' && check != 2)
		{
			cmd = remove_quote(cmd, '\'');
			check = 1;
		}
		printf("#%d\n", check);
		if (cmd[i] == '$' && check_doll(cmd, i) && check != 1)
			new = fill_new(new, cmd, env, &i);
		else
		{
			temp = malloc(2);
			temp[0] = cmd[i++];
			temp[1] = '\0';
			new = ft_strjoin(new, temp);
			free (temp);
		}
	}
	return (new);
}