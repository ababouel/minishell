/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:20:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 19:58:29 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LEXER_H
#define LEXER_H

# include "token.h"

void    init_lexer(char *line, t_lstok *lstok);

#endif