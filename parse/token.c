/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/16 23:36:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"

static const char *symb[] = {
        PIPE,AMPAND,SINQTE,
		ASTERK,DQUOTE,DOLLAR,RINPUT,
		ROUTPUT,EXCLAM,OTHER,EOL};
        
t_token *init_token(const char *type,char *value)
{
    t_token *tok;
	
    tok = malloc(sizeof(t_token));
    tok->type = (char *)type;
    tok->value = value;
    return (tok);
 }

int	checkdata(t_lsnode *lstok ,char str, const char **symb)
{
	int	x;
	int y;

	x = 0;
	while (symb[x])
	{
		y = 0;
		while (symb[x][y])
		{
			if (symb[x][y] == str)
			{
				token = init_token(symb[x], &str);
				ins_next_node(lstok, (void *) token);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int chektok(t_lsnode *lstok,char *str)
{
	int	x;
	int    y;
	t_token *token;

	x = 0;
	while (symb[x])
	{
		y = 0;
		while (str[y])
		{
			y += checkdata(str[y], symb);
            if (ft_strncmp(&str[y],symb[x]) == 0)
            {
				token = init_token(symb[x], &str[y]);
				ins_next_node(lstok, (void *) token);
				return (1);
			}
			y++;
		}
		x++;
     }
	 token = init_token(symb[9], str);
	 ins_next_node(lstok, (void *) token);
     return (0);
}