/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 21:56:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"
#include "../inc/lstree.h"

void	ft_freestack(t_lsnode *sk)
{
	t_node	*node;
	
	while (sk->head != NULL)
	{
		node = sk->head;
		sk->head = sk->head->next;
		free(node);
	}
	free(sk);
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
	free(sk);
}