/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/28 05:23:22 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lib.h"

t_token	*init_token(int type, char *value)
{
	t_token	*tok;

	tok = ft_calloc(1, sizeof(t_token));
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}
