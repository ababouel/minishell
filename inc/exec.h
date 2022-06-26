/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:09:46 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 18:10:30 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "lib.h"
# include "lstree.h"
# include <sys/wait.h>

char    *ft_which(char *cmd, char **env);
void    exec_cmd(t_cmd *cmd);
int     forcked();
int     filein(t_redicio *redic);
int     piped(int *fd);
void    exec_redic(t_redicio *redic,t_cmd *cmd);
void	built(t_cmd *cmd);
void	ft_cd(t_cmd *cmd);
void	ft_echo(char **line);
void	ft_pwd(void);
void	ft_env(t_cmd *cmd);
void	ft_export(t_cmd *cmd);
void	ft_unset(t_cmd *cmd);
void	handler(int	hand);
int		printtoken(t_lsnode *lstok);
int     first_check(t_token *temp);
int		second_check(t_token *temp);
char	*search_var(char *cmd, char **env);

#endif
