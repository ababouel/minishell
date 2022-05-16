/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsnode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:30:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/16 22:37:40 by ababouel         ###   ########.fr       */
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

int				ins_next_node(t_lsnode *stack, void *data);
void			init_stack(t_lsnode *stack);
void			ft_freestack(t_lsnode *sk);
unsigned int	is_delim(char c, char *delim);

#endif