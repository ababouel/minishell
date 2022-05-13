/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:35:48 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/12 23:52:48 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_read_line()
// {
// 	char	*line;

// 	line = readline("\nsh>>> ");
// 	return (line);
// }

int	main()
{
	char	*line;
	char	**str;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	str = NULL;
	while (1)
	{
		line = readline("sh>>> ");
		if (ft_strlen(line) > 0)
			add_history(line);
		// while (line[i] != ' ')
		// {
		// 	str[j][i] = line[i];
		// 	i++;
		// }
		// ft_joinargs(str, line);
		// if (!ft_strcmp(str[i], "echo"))
		// {
		// 	j = i;
		// 	while (line[++j])
				// printf("%s", str[0]);
		// 	printf("\n");
		// }
		if (!ft_strcmp(line, "exit"))
			break ;
	}
	return (0);
}
