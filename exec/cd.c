/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/21 16:36:13 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char	*cd_home(char **env)
{
	char	*home;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (ft_strncmp(env[i], "HOME", j) == 0)
		{
			home = malloc(sizeof(char) + ft_strlen(env[i]) - j);
			while (env[i][j])
				home[l++] = env[i][++j];
			return (home);
		}
		i++;
	}
	return (NULL);
}

void	ft_env_oldpwd(char **env)
{
	char	str[100];
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (getcwd(str, sizeof(str)) == NULL)
		return ;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "OLDPWD", ft_strlen("OLDPWD")))
		{
			while (env[i][j] != '=')
				j++;
			while (str[len])
				env[i][++j] = str[len++];
			env[i][++j] = '\0';
			break ;
		}
		i++;
	}
}

void	ft_env_pwd(char **env)
{
	char	str[100];
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (getcwd(str, sizeof(str)) == NULL)
		return ;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD", ft_strlen("PWD")))
		{
			while (env[i][j] != '=')
				j++;
			while (str[len])
				env[i][++j] = str[len++];
			env[i][++j] = '\0';
			break ;
		}
		i++;
	}
}

int	ft_cd(t_cmd *cmd)
{
	char	*home;

	ft_env_oldpwd(cmd->env);
	if (!cmd->cmdarg[1])
	{
		home = cd_home(cmd->env);
		if (!home)
			return (printf("cd: HOME not set\n"), 1);
		chdir(home);
		return (0);
	}
	if (chdir(cmd->cmdarg[1]) == -1)
	{
		printf("cd: %s: No such file or directory\n", cmd->cmdarg[1]);
		return (1);
	}
	ft_env_pwd(cmd->env);
	return (0);
}
