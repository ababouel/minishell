/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:30:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 01:26:16 by ababouel         ###   ########.fr       */
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