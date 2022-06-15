/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:01:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/15 03:39:46 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

char    *ft_which(char **av, t_env *sh)
{
	char	*str;
	char	**spl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sh->envi[i])
	{
		if (!ft_strncmp(sh->envi[i], "PATH", ft_strlen("PATH")))
		{
			spl = ft_split(sh->envi[i] + 5, ':');
			while (spl[j])
			{
				str = ft_strjoin(spl[j], "/");
				str = ft_strjoin(str, av[1]);
				if (!access(str, X_OK))
					return (ft_strdup(str));	
				j++;
			}
		}
		i++;
	}
}