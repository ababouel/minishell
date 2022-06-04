/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:34:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/04 16:06:01 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_which(char **av, t_env *sh)
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
					execve(str, &av[1], sh->envi);
				j++;
			}
		}
		i++;
	}
}
