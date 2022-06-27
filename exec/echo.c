/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:25:44 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/27 02:46:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	check_echo(char **line, char **env, int i, int j)
{
	while (line[i])
	{
		if (line[i][0] == '$')
		{
			line[i] = search_var(line[i], env);
			if (line[i])
				printf("%s", line[i]);
		}
		else
			printf("%s", line[i]);
		i++;
		if (i != j)
			printf(" ");
	}
}

void	ft_echo(char **line, char **env)
{
	int	i;
	int	j;
	int	check;

	(void)env;
	i = 1;
	j = 0;
	check = 0;
	if (!line[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (line[j])
		j++;
	if (!ft_strncmp(line[1], "-n", ft_strlen(line[1])))
	{
		i++;
		check = 1;
	}
	check_echo(line, env, i, j);
	if (check == 0)
		printf("\n");
}
