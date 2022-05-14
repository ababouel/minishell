/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 01:46:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"
;
void    init_lexer(char *line, t_lsnode *lstok)
{
    char    **str;
    int		x;
    
	x = 0;
    str = ft_split(line, WHITESP[0]);
    while (str[x])
	{
        chektok(lstok, str[x]);
        x++;
	}
}