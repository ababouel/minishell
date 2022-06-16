/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:28:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 19:56:19 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_token *checkcondition(t_lexer *lexer, t_token *token)
{
    lexer_advance(lexer);
    return (lexer_advance_with(lexer, token));
}

t_token *lexer_parse_option(t_lexer *lexer)
{
	char	*value;
		
	value = ft_calloc(2, sizeof(char));
	ft_strcat(value, &lexer->c);
	ft_strcat(value,"\0");
	lexer_advance(lexer);
	while (is_alpha(lexer->c))
	{
		value = ft_realloc(value, (ft_strlen(value) + 2) * sizeof(char));
		ft_strcat(value, &lexer->c);
		ft_strcat(value,"\0");
		lexer_advance(lexer);
	}
	return (init_token(TOKEN_OPTION, value));	
}

t_token *lexer_parse_arg(t_lexer *lexer,t_lsnode *lsnode)
{
	char	*value;
	t_token	*tail;
	
	value = ft_calloc(1, sizeof(char));
	tail = (t_token *)lsnode->tail->value;
	while (is_filename(lexer->c))
	{
		value = ft_realloc(value, (ft_strlen(value) + 2) * sizeof(char));
		ft_strcat(value, &lexer->c);
		ft_strcat(value,"\0");
		lexer_advance(lexer);
	}
	if (tail->type == TOKEN_DAND || tail->type == TOKEN_PIPE
		|| tail->type == TOKEN_DPIPE)
		return (init_token(TOKEN_CMD, value));
	if (tail->type == TOKEN_RINPUT || tail->type == TOKEN_DRINPUT
		|| tail->type == TOKEN_DROUTPUT|| tail->type == TOKEN_ROUTPUT)
		return (init_token(TOKEN_NAME, value));
	else
		return (init_token(TOKEN_ARG, value));	
}

t_token	*lexer_next_token(t_lexer *lexer, t_lsnode *lsnode)
{
	while (lexer->c != '\0')
	{
        lexer_whitespace(lexer);
        if (lexer->c == '-')
            return (lexer_parse_option(lexer));
		if (lexer->c == '|' && lexer->src[lexer->i + 1] == '|')
            return (checkcondition(lexer, init_token(TOKEN_DPIPE, "||")));
		if (lexer->c == '&' && lexer->src[lexer->i + 1] == '&')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "&&")));
		if (lexer->c == '|')
            return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));
		if (lexer->c == '&')
            return (lexer_advance_with(lexer, init_token(TOKEN_AND, "&")));
		if(lexer->c == '(')
			return (lexer_advance_with(lexer, init_token(TOKEN_RPAREN, "(")));
		if(lexer->c == ')')
			return (lexer_advance_with(lexer, init_token(TOKEN_LPAREN, ")")));
		if(lexer->c == '\'')
			return (lexer_advance_with(lexer, init_token(TOKEN_SINQTE, "'")));
		if(lexer->c == '*')
			return (lexer_advance_with(lexer, init_token(TOKEN_ASTERK, "*")));
		if(lexer->c == '$')
			return (lexer_advance_with(lexer, init_token(TOKEN_DOLLAR, "$")));
		if(lexer->c == '"')
			return (lexer_advance_with(lexer, init_token(TOKEN_DQUOTE, "\"")));
		if (lexer->c == '<' && lexer->src[lexer->i + 1] == '<')
            return (checkcondition(lexer, init_token(TOKEN_DAND, "<<")));
		if (lexer->c == '>' && lexer->src[lexer->i + 1] == '>')
            return (checkcondition(lexer, init_token(TOKEN_DROUTPUT,">>")));
        if (lexer->c == '<')
            return (lexer_advance_with(lexer, init_token(TOKEN_RINPUT, "<")));
		if (lexer->c == '>')
            return (lexer_advance_with(lexer, init_token(TOKEN_ROUTPUT, ">"))); 
		if (lexer->c == '?')
			return (lexer_advance_with(lexer, init_token(TOKEN_EXCLAM, "?")));
		if (is_alpha(lexer->c) && lsnode->head == NULL)
			return (lexer_parse_cmd(lexer));
		if (is_filename(lexer->c))
			return (lexer_parse_arg(lexer, lsnode));
	}
	return (init_token(TOKEN_EOL, "\0"));
}
