/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/17 19:32:00 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#include "lib.h"
# define WHITESP	" \t\r\n\v"

typedef enum	e_type
{
	TOKEN_CMD,
	TOKEN_ARG,
	TOKEN_PIPE,
	TOKEN_DPIPE,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_AND,
	TOKEN_DAND,
	TOKEN_SINQTE,
	TOKEN_ASTERK,
	TOKEN_DOLLAR,
	TOKEN_DQUOTE,	
	TOKEN_DRINPUT,	
	TOKEN_RINPUT,	
	TOKEN_DROUTPUT,	
	TOKEN_ROUTPUT,
	TOKEN_EXCLAM,
	TOKEN_EOL
}	t_type;

typedef struct	s_token
{
	t_type	*type;
	char	*value;	
}	t_token;

t_token	*init_token(t_type type, char *value);

#endif