/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/04 10:28:22 by ababouel         ###   ########.fr       */
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
		free(node);
		if (temp->next != NULL)
			temp = temp->next;
	}
	free(sk);
	sk = NULL;	
}