/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/02 16:12:18 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define WHITESP	" \t\r\n\v"
typedef enum	e_type
{
	TOKEN_PIPE = 0,
	TOKEN_DPIPE = 1,
	TOKEN_LPAREN = 2,
	TOKEN_RPAREN = 3,
	TOKEN_DAND = 4,
	TOKEN_DQUOTE =  5,	
	TOKEN_SINQTE = 6,
	TOKEN_ASTERK = 7,
	TOKEN_DOLLAR =  8,
	TOKEN_SPACE =  9,
	TOKEN_DRINPUT =  10,	
	TOKEN_RINPUT =  11,	
	TOKEN_DROUTPUT =  12,	
	TOKEN_ROUTPUT =  13,
	TOKEN_EXCLAM =  14,
	TOKEN_EXP = 15,
	TOKEN_EOL =  16,
}	t_type;

typedef struct	s_token
{
	t_type			type;
	char			*value;
	struct	s_token	*next;
	struct s_token *prev;
}	t_token;

typedef struct s_lsnode
{
	int		size;
	t_token	*head;
	t_token	*tail; 
}	t_lsnode;


t_token	*init_token(int type, char *value);
int		ft_filter_token(t_lsnode *lstk);

#endif