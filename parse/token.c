/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/13 19:43:59 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.h"
#include "../inc/token.h"
#include "../inc/lexer.h"

t_token	*init_token(char *type, char *value)
{
	t_token	*tok;
	tok = malloc(sizeof(t_token));
	tok->type = type;
	tok->value = value;
	return (tok);
}

int	chektok(t_lstoken lstok,char *str, char **type)
{
    size_t  size;
    int     x;

    size = ft_strlen(str);
    x = 0;
    while (type[x])
    {
        if (ft_strncmp(str,type[x],size) == 0)
        {
            init_token(type, str);
            return (1);
        }
        x++;
    }
    return (0);
}