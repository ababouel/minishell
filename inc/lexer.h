/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:20:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 01:44:42 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LEXER_H
#define LEXER_H

#include "token.h"

void    init_lexer(char *line, t_lsnode *lstok);

#endif