/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:01:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 01:55:05 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**ft_freedata(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
	return (data);
}

char    *ft_which(char *cmd, char **env)
{
	char	*str;
	char	**spl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", strlen("PATH")) == 0)
		{
			spl = ft_split(env[i], ":");
			while (spl[j])
			{
				str = ft_strjoin(spl[j], "/");
				str = ft_strjoin(str, cmd);
				if (!access(str, X_OK))
				{
					ft_freedata(spl);
					return (ft_strdup(str));	
				}
				j++;
			}
		}
		i++;
	}

	return (NULL);
}