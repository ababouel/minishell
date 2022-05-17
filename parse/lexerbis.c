/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:28:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/18 00:02:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


static t_token *checkcondition(t_lexer *lexer, t_token *token)
{
    lexer_advance(lexer);
    return (lexer_advance_with(lexer, token));
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0')
	{
        lexer_whitespace(lexer);
		if(is_alpha(lexer->c))
			return (lexer_parse_id(lexer));
        if (lexer->c == '-')
            return (lexer_advance_with(lexer, init_token(TOKEN_OPTION, "-")));
		else if (lexer->c == '|' && lexer->src[lexer->i + 1] == '|')
            return (checkcondition(lexer, init_token(TOKEN_DPIPE, "||")));
		else if (lexer->c == '&' && lexer->src[lexer->i + 1] == '&')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "&&")));
		else if (lexer->c == '|')
            return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));
		else if (lexer->c == '&')
            return (lexer_advance_with(lexer, init_token(TOKEN_AND, "&")));
		else if(lexer->c == '(')
			return (lexer_advance_with(lexer, init_token(TOKEN_RPAREN, "(")));
		else if(lexer->c == ')')
			return (lexer_advance_with(lexer, init_token(TOKEN_LPAREN, ")")));
		else if(lexer->c == '\'')
			return (lexer_advance_with(lexer, init_token(TOKEN_SINQTE, "'")));
		else if(lexer->c == '*')
			return (lexer_advance_with(lexer, init_token(TOKEN_ASTERK, "*")));
		else if(lexer->c == '$')
			return (lexer_advance_with(lexer, init_token(TOKEN_DOLLAR, "$")));
		else if(lexer->c == '"')
			return (lexer_advance_with(lexer, init_token(TOKEN_DQUOTE, "\"")));
		else if (lexer->c == '<' && lexer->src[lexer->i + 1] == '<')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "<<")));
		else if (lexer->c == '>' && lexer->src[lexer->i + 1] == '>')
            return (checkcondition(lexer, init_token(TOKEN_DROUTPUT,">>")));
        else if (lexer->c == '<')
            return (lexer_advance_with(lexer, init_token(TOKEN_RINPUT, "<")));
		else if (lexer->c == '>')
            return (lexer_advance_with(lexer, init_token(TOKEN_ROUTPUT, ">"))); 
		else if (lexer->c == '?')
			return (lexer_advance_with(lexer, init_token(TOKEN_EXCLAM, "?")));
	}
	return (init_token(TOKEN_EOL, "\0"));
}