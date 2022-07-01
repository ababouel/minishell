/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:33:37 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 06:38:54 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "token.h"

int				ins_next_node(t_lsnode *stack, t_token *token);
void			init_stack(t_lsnode *stack);
void			ft_freestack(t_lsnode *sk);
unsigned int	is_delim(char c, char *delim);
char			**ft_split(char const *s, char *c);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
int             is_alpha(char c);
size_t			ft_strcat(char *dst, const char *src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_fd(char *s, int fd);
char            *ft_strndup(const char *s, int len);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char            **ft_freememory(char **data, int index);
void            **ft_drealloc(void **ptr, size_t size);
size_t          ft_dstrlen(char **str);
char            *ft_strjoinbis(char *s1, char *s2);
int				ft_isalpha(char c);
int				ft_ischar(char *str);

#endif