/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/04 23:35:45 by sismaili         ###   ########.fr       */
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

t_token	*lexer_redirection(t_lexer *lexer, char *ch, t_type type)
{
	char			*c;
	char			*value;
	unsigned int	len;
	unsigned int	size;
	
	len = 0;
	value = NULL;
	size = ft_strlen(ch);
	while (len++ < size)
		lexer_advance(lexer);
	lexer_whitespace(lexer);
	len = lexer->i;
	c = &lexer->src[len];
	len = 0;
	while (c[len] != '\0')
	{
		if (c[len] == ' ' || c[len] == '>' 
			|| c[len] == '<' || c[len] == '|')
			break ;
		len++;
	}
	if (c[len] == '\0' || c[len] == ' ' || c[len] == '<'
		|| c[len] == '|' || c[len] == '>')
	{
		if (len == 0)
			value = NULL;
		else
			value = ft_strndup(lexer->src + lexer->i, len);
		size = 0;
		while ( size++ < len)
			lexer_advance(lexer);	
	}	
	return (init_token(type, value));
}
	