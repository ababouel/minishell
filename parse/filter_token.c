/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:57:21 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/06 13:08:20 by sismaili         ###   ########.fr       */
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

	i = 0;
	while (value[i])
	{
		if (value[i] == '\'')
			return (0);
		else if (value[i] == '"')
			return (2);
		i++;
	}
	return (0);
}

char	*remove_quote(char *value, char c, int len)
{
	int	i;

	i = -1;
	while (value[++i] && i <= len)
	{
		if (value[i] == c)
		{
			while (value[i])
			{
				value[i] = value[i + 1];
				i++;
			}
			i = -1;
		}
	}
	return (value);
}

int	ft_filter_token(t_lsnode *lstok, char **env)
{
	t_token	*temp;
	int		check;

	(void)env;
	temp = lstok->head;
	while (temp)
	{
		if (!check_squote(temp->value))
			return (printf("syntax error\n"), 0);
		if (!check_dquote(temp->value))
			return (printf("syntax error\n"), 0);
		check = check_check(temp->value);
		if (check == 2)
			temp->value = remove_quote(temp->value, '\"', ft_strlen(temp->value));
		temp = temp->next;
	}
	return (check);
}