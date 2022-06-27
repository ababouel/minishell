/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:45:33 by sismaili          #+#    #+#             */
/*   Updated: 2022/06/24 21:57:12 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	first_check(t_token *temp)
{
	if (!ft_ischar(temp->value) && temp->type != 13 && temp->type != 12
		&& temp->type != 11 && temp->type != 9)
		return (0);
	return (1);
}

int	second_check(t_token *temp)
{
	if (!ft_ischar(temp->value) && temp->type != 10
		&& temp->type != 13 && temp->type != 12
		&& temp->type != 11 && temp->type != 9)
		return (0);
	return (1);
}
