/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:51:32 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/25 15:08:40 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstree.h"
#include "exec.h"

void	ft_free_env(t_env *env)
{
	t_val	*node;
	t_val	*temp;

	node = env->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->value);
		temp->value = NULL;
		free(temp);
		temp = NULL;
	}
	init_env(env);
}
