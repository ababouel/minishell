/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 20:28:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

int ins_next_node(t_lsnode *stack, t_node *node, void *data)
{

}

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