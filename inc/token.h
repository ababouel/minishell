/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 00:52:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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
# define OTHER		"a"
# define EOL		'\0'

typedef struct s_token
{
	char	*type;
	char	*value;	
}	t_token;

t_token	*init_token(char *type, char *value);

#endif