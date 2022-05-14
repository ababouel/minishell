/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/14 01:51:24 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"

const char *symb[] = {
		WHITESP,PIPE,AMPAND,SINQTE,
		ASTERK,DQUOTE,DOLLAR,RINPUT,
		ROUTPUT,ROUTAPP,RINDELI,AND_IF,
		AND_OR,DEXCLAM,OTHER,EOL};
        
t_token *init_token(int num,char *value)
{
    t_token *tok;
    tok = malloc(sizeof(t_token));
    tok->type = (char *) symb[num];
     tok->value = value;
     return (tok);
 }
 
 int chektok(t_lsnode *lstok,char *str)
 {
     size_t  size;
     int     x;
 
     x = 0;
     size = ft_strlen(str);
     while (symb[x])
     {
        if (ft_strncmp(str,symb[x],size) == 0)
         {
             ins_next_node(lstok, lstok->head->next,(void *) init_token(x, str));
             return (1);
         }
         x++;
     }
    return (0);
}