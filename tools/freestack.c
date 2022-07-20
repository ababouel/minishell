/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/20 19:04:33 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lib.h"
#include "lstree.h"

static void	freedata(t_data *item)
{
	if (item->cmd.pathcmd != NULL)
		free(item->cmd.pathcmd);
	if (item->cmd.cmdarg != NULL)
		item->cmd.cmdarg = ft_freedt(item->cmd.cmdarg);
	if (item->cmd.name != NULL)
		free(item->cmd.name);
	item->cmd.pathcmd = NULL;
	item->cmd.name = NULL;
	free(item);
	item = NULL;
}

void	ft_freestack(t_lsnode *sk)
{
	t_token	*node;
	t_token	*temp;

	node = sk->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->value);
		temp->value = NULL;
		free(temp);
		temp = NULL;
	}
	init_stack(sk);
}

void	ft_freetree(t_lsdata *sk)
{
	t_data	*node;
	t_data	*temp;

	if (!sk)
		return ;
	temp = sk->head;
	while (temp != NULL)
	{
		node = temp;
		temp = temp->next;
		if (node != NULL)
			freedata(node);
	}
	init_lsdata(sk);
}
