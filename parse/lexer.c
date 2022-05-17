/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/17 20:12:58 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"

t_lexer	init_lexer(char *line)
{
	t_lexer	lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->src = line;
	lexer->i = 0;
	lexer->size = ft_strlen(line);
	lexer->c = lexer->src[lexer->i];
	return (lexer); 
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->size && lexer->src[i] != '\0')
	{
		lexer->i += 1;
		lexer->c = lexer->src[lexer->i];
	}
}

void	lexer_whitespace(t_lexer *lexer)
{
	while (is_delim(lexer->c, WHITESP))
		lexer_advance(lexer);
}

t_token	*lexer_advance_with(t_lexer *lexer, t_token token)
{
	lexer_advance(lexer);
	return (token);
}

t_token *lexer_parse_id(t_lexer *lexer)
{
	char	*value;
	int		i;
	value = malloc(sizeof(char));
	i = lexer->i;
	while (isalpha(lexer->c))
	{
		value = ft_realloc(value, (ft_strlen(value) + 2) * sizeof(char));
		strcat(value, lexer->c);
		strcat(value,'\0');
		lexer_advance(lexer);
	}
	if (i == 0 || lexer->src[i - 1] == '|')
		return (init_token(TOKEN_CMD, value));
	else 
		return (init_token(TOKEN_ARG, value));
}


t_token	*lexer_next_token(t_lexer *lexer)
{
	t_token	*
	while (lexer->c != '\0')
	{
		if(isalpha(lexer->c))
			return (lexer_advance_with(lexer, lexer_parse_id(lexer)));
		if (lexer->c == '|')
		{
			if (lexer->src[lexer->i + 1] == '|')
				return (lexer_advance_with(lexer, init_token(TOKEN_DPIPE, "||")));
			else
				return (lexer_advance_with(lexer, init_token(TOKEN_PIPE, "|")));
		}

		
	}
	return (init_token(TOKEN_EOL, '\0'));
}
