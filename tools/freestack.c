/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/18 20:26:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "lstree.h"
#include "exec.h"

static void freetoken(t_token *item)
{	
	free(item);
	item = NULL;
}

static void freedata(t_data *item)
{
	if(item->cmd.cmdarg != NULL)
		ft_freedt(item->cmd.cmdarg);	
	free(item->cmd.name);	
	free(item);
	item = NULL;
}


void	ft_freestack(t_lsnode *sk)
{
	t_token	*node;
	t_token *temp;
	
	node = sk->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		if (temp != NULL)
			freetoken(temp);
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
	while ( temp != NULL)
	{
		node = temp;
		temp = temp->next;
		if (node != NULL)
			freedata(node);
	}
	init_lsdata(sk);
}