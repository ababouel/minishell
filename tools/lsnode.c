/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 19:35:49 by ababouel         ###   ########.fr       */
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
	new_node = calloc(1,sizeof(t_node));
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

unsigned int is_delim(char c, char *delim)
{
	int x;

	x = 0;
    while(delim[x] != '\0')
    {
        if(c == delim[x])
            return (1);
        x++;
    }
    return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*copy;
	size_t			index;

	copy = (unsigned char *)malloc(count * size);
	if (copy == NULL)
		return (0);
	index = count * size;
	ft_bzero(copy, index);
	return (copy);
}
