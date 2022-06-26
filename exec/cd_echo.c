/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/23 18:38:49 by sismaili         ###   ########.fr       */
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
	if(getcwd(str, sizeof(str)) == NULL)
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
	int		i;
	int		j;
	int		len;
	char	*join;

	i = 0;
	j = 0;
	len = 0;
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

void	ft_echo(char **line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!line[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (line[j])
		j++;
	if (!ft_strncmp(line[1], "-n", ft_strlen(line[1])))
		i++;
	while (line[i])
	{
		printf("%s", line[i++]);
		if (i != j)
			printf(" ");
	}
	if (ft_strncmp(line[1], "-n", ft_strlen(line[1])))
		printf("\n");
}
