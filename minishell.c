/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:13:09 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/20 23:33:55 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	str[100];

	getcwd(str, sizeof(str));
	printf("%s\n", str);
}

void	ft_echo(char **line)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (line[j])
		j++;
	while (line[i])
	{
		if (!ft_strncmp(line[2], "-n", ft_strlen(line[2])))
			i++;
		printf("%s", line[i++]);
		if (i != j)
			printf(" ");
	}
	if (ft_strncmp(line[2], "-n", ft_strlen(line[2])))
		printf("\n");
}

void	ft_cd(char **line, t_env *sh)
{
	int		i;
	int		j;
	int		len;
	char	str[100];
	char	*path;

	i = 0;
	j = 0;
	len = 0;
	if (chdir(line[2]) != -1)
	{
		path = malloc(sizeof(char) * ft_strlen(line[2]));
		path = getcwd(str, sizeof(str));
		while (sh->envi[i])
		{
			if (!ft_strncmp(sh->envi[i], "PWD", ft_strlen("PWD")))
			{
				while (sh->envi[i][j] != '=')
					j++;
				while (path[len])
					sh->envi[i][++j] = path[len++];
				sh->envi[i][++j] = '\0';
				break ;
			}
			i++;
		}
	}
	i = 0;
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}

void	ft_env(char **line, t_env *sh)
{
	int	i;

	i = 0;
	if (line[2])
	{
		printf("env: %s: No such file or directory\n", line[2]);
		return;
	}
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}

void	ft_export(char **line, t_env *sh)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	j = 0;
	len = 0;
	while (sh->envi[len])
		len++;
	while (line[i])
	{
		if ((line[i][0] >= 65 && line[i][0] <= 90) || (line[i][0] >= 97 && line[i][0] <= 122))
		{
			while (line[i][j])
			{
				if (line[i][j] == '=')
				{
					sh->envi[len] = line[i];
					sh->envi[++len] = NULL;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}

void	ft_unset(char **line, t_env *sh)
{
	int	i;
	int	j;

	i = 2;
	while (line[i])
	{
		j = 0;
		while (sh->envi[j])
		{
			if (!ft_strncmp(line[i], sh->envi[j], ft_strlen(line[i])))
			{
				while (sh->envi[j])
				{
					sh->envi[j] = sh->envi[j + 1];
					j++;
					if (sh->envi[j + 1] == NULL)
					{
						sh->envi[j] = NULL;
						break ;
					}
				}
			}
			else
				j++;
		}
		i++;
	}
	// i = 0;
	// while (sh->envi[i])
	// 	printf("%s\n", sh->envi[i++]);
}

int	main(int ac, char **av, char **env)
{
	t_env sh;

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
	}
	return (0);
}