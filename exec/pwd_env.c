/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/27 00:16:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	ft_pwd(void)
{
	char	str[1000];

	if (getcwd(str, sizeof(str)) != NULL)
		printf("%s\n", str);
	return (0);
}

int	ft_env(t_cmd *cmd)
{
	t_val	*head;
	char	*str;

	head = cmd->env->head;
	if (cmd->cmdarg[1])
	{
		// printf("env: %s: No such file or directory\n", cmd->cmdarg[1]);
		str = ft_strjoin("env :", cmd->cmdarg[1]);
		str = ft_strjoinbis(str,": No such file or directory\n");
		ft_putstr_fd(str,2);
		free(str);
		str = NULL;
		return (1);
	}
	while (head)
	{
		printf("%s\n", head->value);
		head = head->next;
	}
	return (0);
}
