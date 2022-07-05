/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:06:02 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/05 22:03:27 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTREE_H
# define LSTREE_H

# include "lexer.h"
# include "lib.h"

int g_pid;

typedef enum	e_mpipe
{
	NUL		= -1,
	START	= 0,
	UPDATE	= 1,
	END		= 2
}	t_statpipe;

typedef struct file
{
  char    *file;
  t_type  type;
} t_file;

typedef struct	s_pipe
{
	int			pfd[2];
	t_statpipe	statpipe;
}	t_pipe;

typedef struct	s_cmd
{
	int		ffd[2];
	int		numfile;
	char	*pathcmd;
	char	**cmdarg;
	char	**env;
	t_file	*name;
}	t_cmd;

typedef struct s_data
{
	t_pipe			pipe;
	t_cmd			cmd;
	struct s_data	*next;
	struct s_data	*prev;
}	t_data;

typedef	struct s_lsdata
{
	int		size;
	int		nupipe;
	t_data	*head;
	t_data	*tail;
}	t_lsdata;

void	init_lsdata(t_lsdata *lstree);
void	parsing(t_lsdata *lstree, t_lsnode *lsnode, char **env);
int		ins_next_tree(t_lsdata *stack, t_data *data);
void	ft_freetree(t_lsdata *sk);
void	parse_cmd(t_data *data, t_token *token, char **env);
t_data	*parse_pipe(t_lsdata *lsdata,t_data *data);
int		ins_next_data(t_lsdata *stack, t_data *data);
int		parse_redic(t_data *lsdata, t_token *token);
t_data	*init_dt(char **env);

#endif