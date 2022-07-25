/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_val.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:15:02 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/25 01:16:00 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_val	*rm_val(t_val *val)
{
	free(val->value);
	val->value = NULL;
	free(val);
	val = NULL;
	return (val);
}

void	rm_var(t_val *val, char *var)
{
	t_val	*result;
	t_val	*tprv;
	t_val	*tnxt;

	tprv = NULL;
	tnxt = NULL;
	result = search_val(val, var);
	if (result && result->value != NULL)
	{
		tprv = result->prev;
		tnxt = result->next;
		if (tprv)
			tprv->next = tnxt;
		if (tnxt)
			tnxt->prev = tprv;
		result = rm_val(result);
	}
}
