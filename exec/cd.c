/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/29 00:59:30 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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

void	ft_cd(t_cmd *cmd)
{	
	char	*join;

	ft_env_oldpwd(cmd->env);
	if (!cmd->cmdarg[1])
		chdir("/Users/sismaili");
	if (chdir(cmd->cmdarg[1]) == -1)
	{
		join = ft_strjoin(cmd->cmdarg[0], ":");
		join = ft_strjoin(join, " ");
		join = ft_strjoin(join, cmd->cmdarg[1]);
		perror(join);
	}
	ft_env_pwd(cmd->env);
}
