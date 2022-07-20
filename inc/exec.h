/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:09:46 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/20 14:13:23 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "lib.h"
# include "lstree.h"
# include "minishell.h"
# include <sys/wait.h>
# include <termios.h>

typedef struct s_gl
{
    int g_pid;
    int state;
}   t_gl;

t_gl	gl;

char    *ft_which(char *cmd, char **env);
void    exec_cmd(t_cmd *cmd);
int     forcked();
int     filein(t_cmd *redic);
int     piped(int *fd);
void    exec_redic(t_cmd *redic,t_cmd *cmd);
void	built(t_data *data, t_lsdata *lsdata);
int		ft_cd(t_cmd *cmd);
int		ft_echo(t_cmd *cmd);
int		ft_pwd(void);
int		ft_env(t_cmd *cmd);
int		ft_export(t_cmd *cmd);
char	**cmdenv(t_cmd *cmd, int i, int j, int size);
char	**exportenv(t_cmd *cmd, int i, int j, int check);
int		ft_unset(t_cmd *cmd);
void	handler(int	hand);
int		printtoken(t_lsnode *lstok);
int     first_check(t_token *temp);
int		second_check(t_token *temp);
char	*search_var(char *cmd, char **env, int check);
char	**bubble_sort(t_cmd *cmd);
void    sort_export(t_cmd *cmd);
char	*search_in_env(char **env, char *var);
char	*return_new(char *new, char **env, int i, int j);
char	*remove_quote(char *value, char c, int len);
void    ft_stat_pipe_dup(t_data *dt, t_lsdata *lsdata);
void    ft_stat_pipe_close(t_data *dt);
void    exec_pipe(t_data *dt);
void    redic_close(t_cmd *cmd);
void    redic_open(t_cmd *cmd);
char	**ft_freedt(char **data);

#endif
