/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:35:48 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/02 16:23:01 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd1(void)
{
	char	str[100];

	getcwd(str, sizeof(str));
	printf("%s\n", str);
}

void	ft_echo1(char *line)
{
	int	i;

	i = ft_strlen("echo");
	if (line[i++] == ' ')
	{
		if (line[i] == '-' && line[++i] == 'n')
		{
			i += 2;
			while (line[i] != '\0')
				printf("%c", line[i++]);
		}
		else
		{
			while (line[i] != '\0')
			{
				printf("%c", line[i++]);
				if (line[i] == '\0')
					printf("\n");
			}
		}
	}
}

void	ft_cd1(char *line)
{
	char	*path;
	int		i;
	int		j;

	i = ft_strlen("cd");
	j = 0;
	path = malloc(sizeof(char) * ft_strlen(line));
	if (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	chdir(path);
	free (path);
}

int	ft_env1(char **env, char *line, t_env *sh)
{
	int		i;

	i = ft_strlen("env");
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	sh->envi = env;
	i = 0;
	while (sh->envi[i])
	{
		printf("%s\n", sh->envi[i]);
		i++;
	}
	return (1);
}

// void	ft_export(char *line, t_env *sh)
// {
// 	int	i;
// 	int	j;

// 	i = ft_strlen("export");
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == ' ')
// 			i++;
// 		else if ((line[i] >= 65 && line[i] <= 90) || line[i] >= 97 && line[i] <= 122)
// 		{
// 			j = i;
// 			while ((line[i] >= 65 && line[i] <= 90) || line[i] >= 97 && line[i] <= 122)
// 			{
// 				if (line[i] == '=')
// 				{
					
// 				}
// 				i++;
// 			}
// 		}
// 	}
// }

int	main(int ac, char **av)
{
	// char	*line;
	// t_env	sh;
	// int		i;
	// int		j;

	(void)av;
	if (ac > 1)
	{
		// while (1)
		// {
		// 	line = readline("sh>>> ");
		// 	i = 0;
		// 	j = 0;
		// 	if (ft_strlen(line) > 0)
		// 		add_history(line);
		// 	if (!ft_strncmp(line, "pwd", ft_strlen("pwd")))
		// 		ft_pwd();
		// 	else if (!ft_strncmp(line, "echo", ft_strlen("echo")))
		// 		ft_echo(line);
		// 	else if (!ft_strncmp(line, "cd", ft_strlen("cd")))
		// 		ft_cd(line);
		// 	else if (!ft_strncmp(line, "env", ft_strlen("env")))
		// 		ft_env(env, line, &sh);
		// 	// else if (!ft_strncmp(line, "export", ft_strlen("export")))
		// 	// 	ft_export(line, &sh);
		// 	else if (!ft_strncmp(line, "exit", ft_strlen(line)))
		// 		break ;
		// }
	}
	return (0);
}
