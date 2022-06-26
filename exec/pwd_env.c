/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/21 12:37:51 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	ft_pwd(void)
{
	char	str[100];

	if (getcwd(str, sizeof(str)) != NULL)
		printf("%s\n", str);
}

void	ft_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmdarg[1])
	{
		printf("env: %s: No such file or directory\n", cmd->cmdarg[1]);
		return ;
	}
	while (cmd->env[i])
		printf("%s\n", cmd->env[i++]);
}
