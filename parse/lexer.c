/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 16:04:11 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"
#include "../inc/lib.h"

void    init_lexer(char *line)
{
    char    **str;
    int		x;
	int		y;

	x = 0;
    str = ft_split(line, WHITESP[0]);
    while (str[x])
	{
		
	}
}