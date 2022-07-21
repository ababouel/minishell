/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/21 02:19:56 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

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
	ft_env_oldpwd(cmd->env);
	if (!cmd->cmdarg[1])
	{
		chdir("/Users/ababouel");
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
