/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:52:07 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 19:56:22 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"
#include "../inc/lib.h"

void    init_lexer(char *line, t_lstok *lstok)
{
    char    **str;
    int		x;
	int		y;
    size_t  size;

	x = 0;
    str = ft_split(line, WHITESP[0]);
    while (str[x])
	{
        chektok(str, type);
        x++;
	}
}