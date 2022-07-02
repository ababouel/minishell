/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/02 05:26:12 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lib.h"
#include "exec.h"

t_token	*init_token(int type, char *value)
{
	t_token	*tok;

	tok = ft_calloc(1, sizeof(t_token));
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}

static char	*rpl_sinqte(char *str)
{
	char	*value;
	int		len;
	char	c;
	int		size;

	c = 0;
	len = 0;
	size = ft_strlen(str);
	value = ft_calloc(1, sizeof(char));
	while (len < size)
	{
		if (str[len] != '\'')
		{
			c = str[len];
			ft_strcat(value, &c);
			value = ft_realloc(value, (ft_strlen(value) + 1) * sizeof(char));
		}
		len++;
	}
	ft_strcat(value, "\0");
	free(str);
	str = NULL;
	return (value);
}

// static	char	*rpl_dqte(char *str)
// {
// 	return (NULL);
// }

static char	*rpl_dollar(char *str, char **env)
{
	int		len;
	char	**arrstr;
	char	*data;

	len = 0;
	data = NULL;
	arrstr = ft_split(str," ;*<>&|/\0");
	while (arrstr[len])
	{
		data = search_var(arrstr[len], env);
		if (data)
			arrstr[len] = ft_strdup(data);
		len++;
	}
	len = 0;
	while (arrstr[len])
	{
		ft_strjoin()
	}
	return ()
}

int	ft_filter_token(t_lsnode *lstk)
{
	t_token	*tk;

	tk = lstk->head;
	while (tk != NULL)
	{
		if (tk->type == TOKEN_EXP)
			tk->value = rpl_sinqte(tk->value);
		if (tk != NULL)
			tk = tk->next;
	}
	return (0);
}
