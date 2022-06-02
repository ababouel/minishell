/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/21 19:31:43 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(void)
{
	char	str[100];

	getcwd(str, sizeof(str));
	printf("%s\n", str);
}

void	ft_env(char **line, t_env *sh)
{
	int	i;

	i = 0;
	if (line[2])
	{
		printf("env: %s: No such file or directory\n", line[2]);
		return ;
	}
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}
