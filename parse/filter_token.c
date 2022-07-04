/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:57:21 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/04 16:59:53 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_squote(char *value)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (value[i])
	{
		if (value[i] == '\'')
			check += 1;
		i++;
	}
	if (check % 2 == 0)
		return (1);
	return (0);
}

int	check_dquote(char *value)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (value[i])
	{
		if (value[i] == '"')
			check += 1;
		i++;
	}
	if (check % 2 == 0)
		return (1);
	return (0);
}

int	check_check(char *value)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (value[i])
	{
		if (value[i] == '\'')
		{
			check = 1;
			break ;
		}
		else if (value[i] == '"')
		{
			check = 2;
			break ;
		}
		i++;
	}
	return (check);
}

int	ft_filter_token(t_lsnode *lstok)
{
	t_token	*temp;
	int		i;
	int		check;

	temp = lstok->head;
	check = 0;
	while (temp)
	{
		if (!check_squote(temp->value))
			return (printf("syntax error\n"), 0);
		if (!check_dquote(temp->value))
			return (printf("syntax error\n"), 0);
		check = check_check(temp->value);
		i = 0;
					printf("##%s\n", temp->value);
		while (temp->value[i] && check == 2)
		{
			if (temp->value[i] == '"')
			{
					printf("##%d\n", i);
				while (temp->value[i])
				{
					temp->value[i] = temp->value[i + 1];
					i++;
				}
				i = 0;
			}
			i++;
		}
		printf("%s\n", temp->value);
		temp = temp->next;
	}
	return (0);
}