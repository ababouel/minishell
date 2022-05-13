/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 00:48:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lsnode.h"

void	init_stack(t_lsnode *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

int ins_next_node(t_lsnode *stack, t_node *node, void *data)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (-1);
	new_node->value = data;
	if (node == NULL)
	{
		if (stack->size == 0)
			stack->tail = new_node;
		new_node->next = stack->head;
		stack->head = new_node;
	}
	else
	{
		if (node->next == NULL)
			stack->tail = new_node;
		new_node->next = node->next;
		node->next = new_node;
	}
	stack->size++;
	return (0);
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