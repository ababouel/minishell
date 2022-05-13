/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:21:25 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/12 23:50:58 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

int		ft_strlen(char *s);
void	ft_joinargs(char **str, char **line);
char	*ft_strjoin(char *buffers, char *buff);
char	*ft_strcpy(char *dest, char *src);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);

#endif