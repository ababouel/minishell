/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:01:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/06 09:29:19 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_which(char *cmd, char **env)
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
					return (ft_strdup(str));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
