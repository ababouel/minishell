/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:24:28 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/22 22:15:16 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	check_doll(char *cmd, int i)
{
	if (!cmd[i + 1])
		return (0);
	else if (cmd[i + 1] == '$')
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
		new = ft_strjoinbis(new, var);
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
	if (cmd[*i] && cmd[*i] == '?')
		var[l++] = cmd[(*i)++];
	else
	{
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
	}
	var[l] = '\0';
	new = join_new(new, var, env, l);
	return (new);
}

char	*remove_squote(char *cmd, int *check, int i)
{
	int	len;

	if (cmd[i] == '\'' && *check != 4 && *check != -1)
	{
		len = i;
		cmd = remove_quote(cmd, '\'', len);
		(*check) += 1;
	}
	if (*check % 2 == 0 && *check != 4 && *check != -1)
	{
		cmd = remove_quote(cmd, '\'', len);
		check = 0;
		len = 0;
	}
	return (cmd);
}

int	check_dollar(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*search_var(char *cmd, char **env, int check)
{
	int		i;
	char	*new;
	char	*temp;

	i = 0;
	new = NULL;
	temp = NULL;
	while (cmd[i])
	{
		cmd = remove_squote(cmd, &check, i);
		if (cmd[i] == '$' && check_doll(cmd, i) && check != 1)
			new = fill_new(new, cmd, env, &i);
		else
		{
			temp = malloc(2);
			temp[0] = cmd[i++];
			temp[1] = '\0';
			new = ft_strjoinbis(new, temp);
			free (temp);
		}
	}
		return (new);
}
