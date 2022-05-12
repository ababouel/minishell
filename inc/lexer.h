/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:20:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 00:51:14 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LEXER_H
#define LEXER_H

struct s_lstoken
{
    t_token             *token;
    struct s_lstoken    *next;
}   t_lstoken;

# include "token.h"

void    init_lexer

#endif