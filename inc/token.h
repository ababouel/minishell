/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 01:50:16 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#include "lib.h"
#include "lsnode.h"
# define WHITESP	" \t\r\n\v"
# define PIPE		"|"
# define AMPAND		"&"
# define SINQTE		"'"
# define ASTERK		"*"
# define DQUOTE		"\""
# define DOLLAR		"$"
# define RINPUT		"<"
# define ROUTPUT	">"
# define ROUTAPP	">>"
# define RINDELI	"<<"
# define AND_IF		"&&"
# define AND_OR		"||"
# define DEXCLAM	"$?"
# define OTHER		"word"
# define EOL		"\0"



typedef struct s_token
{
	int		id;
	char	*type;
	char	*value;	
}	t_token;

t_token	*init_token(int num, char *value);
int		chektok(t_lsnode *lstok, char *str);

#endif