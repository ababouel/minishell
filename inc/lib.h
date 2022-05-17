/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:33:37 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/17 19:13:54 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "lsnode.h"
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
char			**ft_split(char const *s, char *c);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
int             isalpha(char c);
size_t			ft_strcat(char *dst, const char *src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strcat(char *dst, const char *src);

#endif