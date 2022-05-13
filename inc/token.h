/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 15:41:34 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define WHITESP	" \t\r\n\v"
# define PIPE		"|"
# define AMPAND		"&"
# define SINQTE		"'"
# define ASTERK		"*"
# define DQUOTE		"""
# define DOLLAR		"$"
# define RINPUT		"<"
# define ROUTPUT	">"
# define ROUTAPP	">>"
# define RINDELI	"<<"
# define AND_IF		"&&"
# define AND_OR		"||"
# define DEXCLAM	"$?"
# define OTHER		"word"
# define EOL		'\0'

typedef struct s_token
{
	int		id;
	char	*type;
	char	*value;	
}	t_token;

t_token	*init_token(char *type, char *value);

#endif