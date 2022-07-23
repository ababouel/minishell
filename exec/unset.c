/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:47:35 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/23 18:51:26 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	error_unset(t_cmd *cmd, int i)
{
	if (ft_isalpha(cmd->cmdarg[i][0]) || cmd->cmdarg[i][0] == '_')
		return (0);
	else
	{
		printf("unset: `%s': not a valid identifier\n", cmd->cmdarg[i]);
		return (1);
	}
}

int	ft_unset(t_cmd *cmd)
{
	int		i;
	t_val	*head;

	i = 1;
	head = cmd->env->head;
	while (cmd->cmdarg[i])
	{
		if (error_unset(cmd, i))
			return (1);
		rm_var(head, cmd->cmdarg[i]);
		rm_var(head, cmd->cmdarg[i]);	
		i++;
	}
	return (0);
}
