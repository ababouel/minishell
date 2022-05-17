/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/17 15:31:56 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"

void	init_stack(t_lsnode *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

int ins_next_node(t_lsnode *stack, void *data)
{
	t_node	*new_node;
	t_node	*temp;
	
	temp = NULL;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (-1);
	new_node->value = data;
	new_node->next = NULL;
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		temp = stack->head;
		while (temp->next)
			temp = temp->next;	
		temp->next = new_node;
		stack->tail = new_node;
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

unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}