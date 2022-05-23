/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:06:02 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/23 23:16:59 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTREE_H
# define LSTREE_H

typedef	enum	treetype
{
	ROUTPUT = 0,
	DROUTPUT = 1,
	DRINPUT = 3,
	RINPUT = 9,
	PIPE = 27,
	DAND = 81,
	DPIPE = 243,
	CMD = 729
};

typedef	struct	s_routput
{
	int	type;
}	t_routput;

typedef	struct	s_droutput
{
	int	type;
}	t_droutput;

typedef	struct	s_rinput
{
	int	type;
}	t_rinput;

typedef	struct	s_drinput
{
	int	type;
}	t_drinput;

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
	int	type;
	
}	t_pipe;

typedef struct	s_cmd
{
	int		type;
	char	*pathcmd;
	char	**cmdarg;
	char	**env;
}	t_cmd;

typedef struct s_tree
{
    union u_c_tree
	{
		t_drinput 	drinput;
		t_rinput 	rinput;
		t_routput	routput;
		t_droutput	droutput;
		t_dand		dand;
		t_dpipe		dpipe;
		t_pipe		pipe;
		t_cmd		cmd;
	};
   	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef	struct s_lstree
{
	int		size;
	t_tree	*root;
}	t_lstree;

#endif