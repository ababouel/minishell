/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:21:25 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/24 16:19:05 by sismaili         ###   ########.fr       */
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

typedef struct s_env
{
	char	**envi;
}	t_env;

int		ft_strlen(char *s);
void	ft_joinargs(char **str, char **line);
int		ft_isalpha(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_export(char **line, t_env *sh);
void	ft_unset(char **line, t_env *sh);
void	ft_cd(char **line, t_env *sh);
void	ft_echo(char **line);
void	ft_pwd(void);
void	ft_env(char **line, t_env *sh);

#endif