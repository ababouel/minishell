/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:01:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/20 15:50:18 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**ft_freedt(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	data = NULL;
	return (data);
}

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
		str = ft_strjoinbis(str, temp);
	}
	free (temp);
	if (!access(str, X_OK))
		return (str);
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_access(char **spl, char *cmd, int j)
{
	char	*str;

	str = ft_strjoin(spl[j], "/");
	str = ft_strjoinbis(str, cmd);
	if (!access(str, X_OK))
	{
		spl = ft_freedt(spl);
		return (str);
	}
	else
	{
		free(str);
		str = NULL;
		return (NULL);
	}
}

char	*ft_which1(char *cmd, char **spl, int j)
{
	char	*access;
	
	if (cmd[0] == '/')
	{
		spl = ft_freedt(spl);
		return (ft_strdup(cmd));
	}
	else if (cmd[0] == '.' && cmd[1] == '/')
	{
		spl = ft_freedt(spl);
		return (point_slash(cmd));
	}
	else
	{
		access = ft_access(spl, cmd, j);
		if (access)
			return (access);
		else
			return (NULL);
	}
}

char	*ft_which(char *cmd, char **env)
{
	char	**spl;
	char	*which;
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
				which = ft_which1(cmd, spl, j);
				if (which)
					return (which);
				j++;
			}
		}
		i++;
	}
	spl = ft_freedt(spl);
	return (NULL);
}
