/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:46:36 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 19:58:20 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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

const char *type[] = {
		WHITESP,PIPE,AMPAND,SINQTE,
		ASTERK,DQUOTE,DOLLAR,RINPUT,
		ROUTPUT,ROUTAPP,RINDELI,AND_IF,
		AND_OR,DEXCLAM,OTHER,EOL,};

typedef struct s_token
{
	int		id;
	char	*type;
	char	*value;	
}	t_token;

struct s_nodetoken
{
    t_token             *token;
    struct s_nodetoken    *next;
}   t_nodetok;

struct s_lstok
{
    int			size;
	t_nodetok	*head;
	t_nodetok	*tail; 
}   t_lstok;

t_token	*init_token(char *type, char *value);
t_token	*insert_lstok(t_lstok *)
int		chektok(char *str, char **type);

#endif