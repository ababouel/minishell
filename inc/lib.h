/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:33:37 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/15 01:00:07 by ababouel         ###   ########.fr       */
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

char			**ft_split(char const *s, char *c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);

#endif