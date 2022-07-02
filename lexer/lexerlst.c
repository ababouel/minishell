/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:29:58 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/02 00:45:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token *lexer_parse_exp(t_lexer *lexer)
{
	char	*value;
	
	value = ft_calloc(1, sizeof(char));
	while (lexer->c != '\0' && !is_delim(lexer->c, " |<>\0"))
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
		if (len == 0)
			value = ft_strdup("\0");
		else
			value = ft_strndup(lexer->src + lexer->i, len);
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
	if (len != 1 && c[1] == '$')
	{
		value = ft_strndup(lexer->src + lexer->i + 1, len - 1);
		lexer->i += len;
		lexer->c = lexer->src[lexer->i];
		return (init_token(TOKEN_DOLLAR, value));	
	}
	else
	{
		value = ft_strndup(lexer->src + lexer->i, len);
		while (len--)
			lexer_advance(lexer);
		return (init_token(TOKEN_EXP,value));
	}
}