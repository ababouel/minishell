/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:16:06 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 20:27:57 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSNODE_H
# define LSNODE_H

typedef struct	s_node
{
	void			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_lsnode
{
	int			size;
	t_node	*head;
	t_node	*tail; 
}	t_lsnode;

int		ins_next_node(t_lsnode *stack, t_node *node, void *data);
void	init_stack(t_lsnode *stack);
void	ft_freestack(t_lsnode *sk);

#endif