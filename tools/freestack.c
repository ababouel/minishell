/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/28 02:28:13 by ababouel         ###   ########.fr       */
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

void	ft_freetree(t_lstree *sk)
{
	t_tree	*node;
	
	while (sk->root != NULL)
	{
		node = sk->root;
		sk->root = sk->root->left;
		free(node);
	}
}