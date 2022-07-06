/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:01:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/06 18:36:24 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*point_slash(char *cmd)
{
	char	*str;
	char	*temp;
	char	cwd[1000];
	int		i;
	int		j;

	i = 0;
	j = 2;
	temp = malloc(sizeof(char) * ft_strlen(cmd) - 1);
	while (cmd[j])
		temp[i++] = cmd[j++];
	temp[i] = '\0';
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		str = ft_strjoin(cwd, "/");
		str = ft_strjoin(str, temp);
	}
	free (temp);
	if (!access(str, X_OK))
		return (ft_strdup(str));
	return (NULL);
}

char	*ft_access(char **spl, char *cmd, int j)
{
	char	*str;

	str = ft_strjoin(spl[j], "/");
	str = ft_strjoin(str, cmd);
	if (!access(str, X_OK))
		return (ft_strdup(str));
	else
		return (NULL);
}

char	*ft_which(char *cmd, char **env)
{
	char	**spl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", strlen("PATH")) == 0)
		{
			spl = ft_split(env[i], ":");
			while (spl[j])
			{
				if (cmd[0] == '/')
					return (ft_strdup(cmd));
				else if (cmd[0] == '.' && cmd[1] == '/')
					return (point_slash(cmd));
				else
					return (ft_access(spl, cmd, j));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
