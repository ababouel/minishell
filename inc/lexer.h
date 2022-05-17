/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:20:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/17 22:55:35 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LEXER_H
#define LEXER_H

#include "token.h"

typedef struct s_lexer
{
    char			*src;
    size_t			size;
    char			c;
    unsigned int	i;
}   t_lexer;

t_lexer	*init_lexer(char *line);
void	lexer_advance(t_lexer *lexer);
t_token	*lexer_next_token(t_lexer *lexer);
t_token	*lexer_parse_id(t_lexer *lexer);
t_token	*lexer_next_token(t_lexer *lexer);
t_token	*lexer_advance_with(t_lexer *lexer, t_token *token);
void	lexer_whitespace(t_lexer *lexer);
#endif