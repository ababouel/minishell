/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:13:09 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/04 15:09:20 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	handler(int	hand)
{
	if (hand == SIGINT)
	{
		write(1, "\nsh>> ", 6);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	sh;
	char	*str;

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
		else
			ft_which(av, &sh);
	}
	else
	{
		while(1)
		{
			signal(SIGINT, handler);
			str = readline("sh>> ");
			if (ft_strlen(str) > 0)
			{
				add_history(str);
				printf("%s\n", str);
			}
			signal(SIGQUIT, SIG_IGN);
			if (!str)
			{
				if (get_next_line(0) == 0)
				{
					write(1, "exit\n", 5);
					exit(0);
				}
			}
			else if (!ft_strncmp(str, "exit", ft_strlen(str)))
			{
				write(1, "exit\n", 6);
				exit(0);
			}
		}
	}
	return (0);
}
