/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:40:14 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/23 18:24:08 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_val	*exportenv(t_cmd *cmd, int i, int j, int check)
{
	t_val	*result;

	result = NULL;
	if (cmd->cmdarg[i][j] != '+' && check == 1)
		return (printf("export: `%s': not a valid identifier\n",
				cmd->cmdarg[i]), NULL);
	else
	{
		result = search_val(cmd->env->head, cmd->cmdarg[i]);
		if (result)
			return NULL;
		else
		{
			result = add_val(cmd->cmdarg[i]);
			return (result);
		}
	}
}
