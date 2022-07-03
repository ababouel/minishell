/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/03 17:01:35 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "lstree.h"

void	ft_freestack(t_lsnode *sk)
{
	t_token	*node;
	t_token *temp;
	
	node = sk->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(node->value);
		free(temp);
	}
	// free(sk);
}

void	ft_freetree(t_lsdata **sk)
{
	t_data	*node;
	if (!sk || !*sk)
		return ;
	while ((*sk)->head != NULL)
	{
		node = (*sk)->head;	
		(*sk)->head = (*sk)->head->next;
		free(node);
		node->cmd.env = NULL;
		node->next = NULL;
		node->prev = NULL;
	}
	free(*sk);
	*sk = NULL;	
}