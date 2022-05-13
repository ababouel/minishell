/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 00:41:56 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"

t_token	*init_token(const char *type, char *value)
{
	t_token	*tok;
	tok = malloc(sizeof(t_token));
	tok->type = (char *)type;
	tok->value = value;
	return (tok);
}

int	chektok(t_lsnode *lstok,char *str, const char **type)
{
    size_t  size;
    int     x;

    x = 0;
    size = ft_strlen(str);
    while (type[x])
    {
        if (ft_strncmp(str,type[x],size) == 0)
        {
            ins_next_node(lstok,lstok->head->next,(void *) init_token(type[x], str));
            return (1);
        }
        x++;
    }
    return (0);
}