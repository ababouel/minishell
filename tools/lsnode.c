/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:15:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/23 00:29:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	init_stack(t_lsnode *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

int ins_next_node(t_lsnode *stack, t_token *token)
{
	t_token	*temp;
	
	temp = stack->head;	
	if (stack->head == NULL)
	{
		stack->head = token;
		stack->tail = token;
	}
	else
	{
		temp = stack->head;
		while (temp->next)
			temp = temp->next;	
		temp->next = token;
		stack->tail = token;
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

size_t ft_dstrlen(char **str)
{
	size_t	len;

	len = 0;
	while (str[len] != NULL)
		len++;
	return (len);	
}
