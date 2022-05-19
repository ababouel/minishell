/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/19 20:03:58 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#include "lib.h"
# define WHITESP	" \t\r\n\v"

typedef enum	e_type
{
	TOKEN_CMD = 0,
	TOKEN_ARG = 1,
	TOKEN_PIPE = 2,
	TOKEN_DPIPE = 3,
	TOKEN_LPAREN = 4,
	TOKEN_RPAREN = 5,
	TOKEN_AND = 6,
	TOKEN_DAND = 7,
	TOKEN_SINQTE = 8,
	TOKEN_ASTERK = 9,
	TOKEN_DOLLAR = 10,
	TOKEN_DQUOTE = 11,	
	TOKEN_DRINPUT = 12,	
	TOKEN_RINPUT = 13,	
	TOKEN_DROUTPUT = 14,	
	TOKEN_ROUTPUT = 15,
	TOKEN_EXCLAM = 16,
	TOKEN_EOL = 17,
	TOKEN_OPTION = 18
}	t_type;

typedef struct	s_token
{
	t_type	type;
	char	*value;	
}	t_token;

t_token	*init_token(int type, char *value);

#endif