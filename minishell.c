/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:13:09 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/24 15:12:24 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_env	sh;

	if (ac > 1)
	{
		sh.envi = env;
		if (!ft_strncmp(av[1], "pwd", ft_strlen(av[1])))
			ft_pwd();
		else if (!ft_strncmp(av[1], "echo", ft_strlen(av[1])))
			ft_echo(av);
		else if (!ft_strncmp(av[1], "cd", ft_strlen(av[1])))
			ft_cd(av, &sh);
		else if (!ft_strncmp(av[1], "env", ft_strlen(av[1])))
			ft_env(av, &sh);
		else if (!ft_strncmp(av[1], "export", ft_strlen(av[1])))
			ft_export(av, &sh);
		else if (!ft_strncmp(av[1], "unset", ft_strlen(av[1])))
			ft_unset(av, &sh);
		else if (!ft_strncmp(av[1], "exit", ft_strlen(av[1])))
			exit(0);
	}
	return (0);
}
