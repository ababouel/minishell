/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:28:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/02 01:06:30 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*checkcondition(t_lexer *lexer, t_token *token)
{
	lexer_advance(lexer);
	return (lexer_advance_with(lexer, token));
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	while (lexer->i < lexer->size && lexer->c != '\0')
	{
		if (lexer->c == ' ')
			return (lexer_advance_with(lexer, init_token(TOKEN_SPACE, " ")));
		if (lexer->c == '|')
		    return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));
		if(lexer->c == '$')
			return (lexer_parse_dollar(lexer));
		if (lexer->c == '<' && lexer->src[lexer->i + 1] == '<')
		    return (lexer_redirection(lexer, "<<", TOKEN_DRINPUT));
		if (lexer->c == '>' && lexer->src[lexer->i + 1] == '>')
		    return (lexer_redirection(lexer, ">>", TOKEN_DROUTPUT));
		if (lexer->c == '<')
		    return (lexer_redirection(lexer, "<", TOKEN_RINPUT));
		if (lexer->c == '>')
		    return (lexer_redirection(lexer, ">", TOKEN_ROUTPUT)); 
		return (lexer_parse_exp(lexer));
	}
	return (init_token(TOKEN_EOL, "\0"));
}

// t_token	*lexer_next_token(t_lexer *lexer)
// {
// 	while (lexer->i < lexer->size && lexer->c != '\0')
// 	{
//         if (lexer->c == ' ')
// 			lexer_advance(lexer);
// 		if (lexer->c == '|' && lexer->src[lexer->i + 1] == '|')
//             return (checkcondition(lexer, init_token(TOKEN_DPIPE, "||")));
// 		if (lexer->c == '&' && lexer->src[lexer->i + 1] == '&')
//             return (checkcondition(lexer, init_token(TOKEN_DAND, "&&")));
// 		if (lexer->c == '|')
//             return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));	
// 		if(lexer->c == '(')
// 			return (lexer_advance_with(lexer, init_token(TOKEN_RPAREN, "(")));
// 		if(lexer->c == ')')
// 			return (lexer_advance_with(lexer, init_token(TOKEN_LPAREN, ")")));
// 		if(lexer->c == '\'')
// 			return (lexer_parse_quote(lexer, '\'', TOKEN_SINQTE));
// 		if(lexer->c == '*')
// 			return (lexer_advance_with(lexer, init_token(TOKEN_ASTERK, "*")));
// 		if(lexer->c == '$')
// 			return (lexer_parse_dollar(lexer));
// 		if(lexer->c == '"')
// 			return (lexer_parse_quote(lexer, '\"', TOKEN_DQUOTE));
// 		if (lexer->c == '<' && lexer->src[lexer->i + 1] == '<')
//             return (lexer_redirection(lexer, "<<", TOKEN_DRINPUT));
// 		if (lexer->c == '>' && lexer->src[lexer->i + 1] == '>')
//             return (lexer_redirection(lexer, ">>", TOKEN_DROUTPUT));
//         if (lexer->c == '<')
//             return (lexer_redirection(lexer, "<", TOKEN_RINPUT));
// 		if (lexer->c == '>')
//             return (lexer_redirection(lexer, ">", TOKEN_ROUTPUT)); 
// 		return (lexer_parse_exp(lexer));
// 	}
// 	return (init_token(TOKEN_EOL, "\0"));
// }