/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/22 03:04:11 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"

t_lexer	*init_lexer(char *line)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->src = line;
	lexer->i = 0;
	lexer->size = ft_strlen(line);
	lexer->c = lexer->src[lexer->i];
	return (lexer); 
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->size && lexer->src[lexer->i] != '\0')
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

t_token	*lexer_advance_with(t_lexer *lexer, t_token *token)
{
	lexer_advance(lexer);
	return (token);
}

