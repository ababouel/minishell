/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:06:02 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 18:42:16 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTREE_H
# define LSTREE_H

# include "lexer.h"
# include "lib.h"
typedef enum	e_treetype
{
	REDICIO = 1,	
	PIPE = 27,
	DAND = 81,
	DPIPE = 243,
	CMD = 729
}	t_treetype;

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
// start =>struct parsing 
typedef	struct	s_redicio
{
	int		fd[2];
	t_file	*name;
}	t_redicio;

typedef struct s_dand
{
	int	type;
}	t_dand;

typedef struct	s_dpipe
{
	int	type;
}	t_dpipe;

typedef struct	s_pipe
{
	int			*fd;
	t_statpipe	statpipe;
}	t_pipe;

typedef struct	s_cmd
{
	char	*pathcmd;
	char	**cmdarg;
	char	**env;
	char	**export;
}	t_cmd;
// end =>struct parsing 
// struct of tree and lstree
typedef struct s_tree
{
	union u_c_tree
	{
		t_redicio	redic;
		t_dand		dand;
		t_dpipe		dpipe;
		t_pipe		pipe;
		t_cmd		cmd;
	}	utree;
	t_treetype		type;
   	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef	struct s_lstree
{
	int		size;
	t_tree	*root;
}	t_lstree;

void	init_lstree(t_lstree *lstree);
void	parsing(t_lstree *lstree, t_lsnode *lsnode, char **env);
char	**inject_arg(t_lsnode *nt_tree);
int		ins_next_tree(t_lstree *stack, t_tree *data);
void	ft_freetree(t_lstree *sk);
int		parse_cmd(t_lstree *lstree, t_token *token, char **env);
t_tree  *parse_pipe();
t_token *parse_redic(t_lstree *lstree, t_token *token);
#endif