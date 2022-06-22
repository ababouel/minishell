/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:28:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/22 08:42:01 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_token *checkcondition(t_lexer *lexer, t_token *token)
{
    lexer_advance(lexer);
    return (lexer_advance_with(lexer, token));
}

t_token *lexer_parse_exp(t_lexer *lexer)
{
	char	*value;
	
	value = ft_calloc(1, sizeof(char));
	while (lexer->c != '\0' && !is_delim(lexer->c, " $'\"()|&<>*\0"))
	{
		ft_strcat(value, &lexer->c);
		lexer_advance(lexer);
		value = ft_realloc(value, (ft_strlen(value) + 1) * sizeof(char));
	}
	ft_strcat(value, "\0");
	return (init_token(TOKEN_EXP, value));	
}

t_token *lexer_parse_quote(t_lexer *lexer, char ch, t_type type)
{
	char	*c;
	char	*value;
	int		len;

	len = 0;
	value = NULL;
	c = lexer->src + lexer->i + 1;
	lexer_advance(lexer);
	while (c[len] != '\0')
	{
		if (c[len] == ch)
			break;
		len++;
	}
	if(c[len] == ch)
	{
		value = strndup(lexer->src + lexer->i, len);
		lexer->i += ++len;
		lexer->c = lexer->src[lexer->i];
	}
	return (init_token(type, value));	
}

t_token	*lexer_parse_dollar(t_lexer *lexer)
{
	char	*c;
	char	*value;
	int		len;

	len = 0;
	c = lexer->src + lexer->i;
	while (c[len] != '\0' && !is_delim(c[len], " |&<>"))
		len++;
	if (len != 1 && c[1] != '$')
	{
		value = strndup(lexer->src + lexer->i + 1, len - 1);
		lexer->i += len;
		lexer->c = lexer->src[lexer->i];
		return (init_token(TOKEN_DOLLAR, value));	
	}
	else
	{
		value = strndup(lexer->src + lexer->i, len);
		while (len--)
			lexer_advance(lexer);
		return (init_token(TOKEN_EXP,value));
	}
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0')
	{
        if (lexer->c == ' ')
			return (lexer_advance_with(lexer, init_token(TOKEN_SPACE, " ")));
		if (lexer->c == '|' && lexer->src[lexer->i + 1] == '|')
            return (checkcondition(lexer, init_token(TOKEN_DPIPE, "||")));
		if (lexer->c == '&' && lexer->src[lexer->i + 1] == '&')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "&&")));
		if (lexer->c == '|')
            return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));	
		if(lexer->c == '(')
			return (lexer_advance_with(lexer, init_token(TOKEN_RPAREN, "(")));
		if(lexer->c == ')')
			return (lexer_advance_with(lexer, init_token(TOKEN_LPAREN, ")")));
		if(lexer->c == '\'')
			return (lexer_parse_quote(lexer, '\'', TOKEN_SINQTE));
		if(lexer->c == '*')
			return (lexer_advance_with(lexer, init_token(TOKEN_ASTERK, "*")));
		if(lexer->c == '$')
			return (lexer_parse_dollar(lexer));
		if(lexer->c == '"')
			return (lexer_parse_quote(lexer, '\"', TOKEN_DQUOTE));
		if (lexer->c == '<' && lexer->src[lexer->i + 1] == '<')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "<<")));
		if (lexer->c == '>' && lexer->src[lexer->i + 1] == '>')
            return (checkcondition(lexer, init_token(TOKEN_DROUTPUT, ">>")));
        if (lexer->c == '<')
            return (lexer_advance_with(lexer, init_token(TOKEN_RINPUT, "<")));
		if (lexer->c == '>')
            return (lexer_advance_with(lexer, init_token(TOKEN_ROUTPUT, ">"))); 
		return (lexer_parse_exp(lexer));
	}
	return (init_token(TOKEN_EOL, "\0"));
}
