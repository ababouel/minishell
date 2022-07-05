/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:09:46 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/05 22:07:55 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "lib.h"
# include "lstree.h"
# include <sys/wait.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>

int g_pid;

char    *ft_which(char *cmd, char **env);
void    exec_cmd(t_cmd *cmd);
int     forcked();
int     filein(t_cmd *redic);
int     piped(int *fd);
void    exec_redic(t_cmd *cmd);
void    built(t_data *data, t_lsdata *lsdata);
void	ft_cd(t_cmd *cmd);
void	ft_echo(char **line, char **env);
void	ft_pwd(t_cmd *cmd);
void	ft_env(t_cmd *cmd);
void	ft_export(t_cmd *cmd);
void	ft_unset(t_cmd *cmd);
void	handler(int	hand);
int		printtoken(t_lsnode *lstok);
int     first_check(t_token *temp);
int		second_check(t_token *temp);
char	*search_var(char *cmd, char **env);
void    ft_stat_pipe_dup(t_data *dt, t_lsdata *lsdata);
void    ft_stat_pipe_close(t_data *dt);
void    exec_pipe(t_data *dt);
void    redic_close(t_cmd *cmd);
void    redic_open(t_cmd *cmd);

#endif
