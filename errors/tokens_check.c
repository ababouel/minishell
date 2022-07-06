/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:24:29 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/06 21:57:12 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

int	check_quotes(t_token *temp)
{
	while (temp)
	{
		if (temp->value == NULL)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	tokens_check(t_token *temp, int i)
{
	if (i == 0)
	{
		if (!first_check(temp))
			return (0);
	}
	else if (i == 1)
	{
		if (!second_check(temp))
			return (perror(temp->value), 0);
	}
	else if (i == 2)
	{
		if (!second_check(temp))
			return (perror(temp->value), 0);
	}
	else if (i > 2)
	{
		if (!ft_ischar(temp->value) && ft_strcmp(temp->value, " ")
			&& ft_strcmp(temp->value, ">") && ft_strcmp(temp->value, ">>")
			&& ft_strcmp(temp->value, "<") && ft_strcmp(temp->value, "<<"))
			return (perror(temp->value), 0);
	}
	return (1);
}

int	check_red(t_token *temp)
{
	if (temp->type == TOKEN_DRINPUT
		|| temp->type == TOKEN_ROUTPUT || temp->type == TOKEN_DROUTPUT
		|| temp->type == TOKEN_RINPUT)
	{
		if (temp->value == NULL)
			return (printf("syntax error near unexpected token `newline'\n"), 0);
	}
	return (1);
}

int	check_pipe(t_token *temp)
{
	if (temp->type == TOKEN_PIPE || temp->type == TOKEN_DPIPE
		|| temp->type == TOKEN_DAND)
	{
		if (!temp->next)
			return (printf("syntax error: unexpected end of file\n"), 0);
		while (temp->next)
		{
			if (temp->next->type == TOKEN_SPACE)
				temp = temp->next;
			if (temp->type == TOKEN_PIPE || temp->type == TOKEN_DPIPE
				|| temp->type == TOKEN_DAND)
				return (printf("syntax error near unexpected token `%s'\n",
						temp->next->value), 0);
			else
				break ;
		}
	}
	return (1);
}

int	printtoken(t_lsnode *lstok)
{
	t_token	*temp;
	int		i;

	i = 0;
	temp = lstok->head;
	while (temp)
	{
		if (!check_quotes(temp))
			return (0);
		if (temp->type == TOKEN_PIPE || temp->type == TOKEN_DPIPE || temp->type == TOKEN_DAND)
			return (printf("syntax error near unexpected token `%s'\n",
					temp->value), 0);
		while (temp->type != TOKEN_PIPE && temp->type != TOKEN_DPIPE && temp->type != TOKEN_DAND)
		{
			if (!tokens_check(temp, i))
				return (0);
			if (!check_red(temp))
				return (0);
			if (!temp->next)
				break ;
			temp = temp->next;
			if (ft_strcmp(temp->value, " "))
				i++;
		}
		if (!check_pipe(temp))
			return (0);
		else
			i = 0;
		temp = temp->next;
	}
	return (1);
}
