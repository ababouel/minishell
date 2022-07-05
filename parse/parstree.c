/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/05 09:40:34 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int  numpipe(t_token *token)
{
    t_token *temp;
    int     len;

    len = 0;
    temp = token;
    while (temp != NULL)
    {
        if (temp->type == TOKEN_PIPE)
            len++;
        temp = temp->next;
    }
    return (len);
}

void    parsing(t_lsdata *lsdata, t_lsnode *lsnode, char **env)
{
    t_token *token;
    t_data  *data;

    data = init_dt(env);
	token = lsnode->head;
    lsdata->nupipe = numpipe(token);
    while (token != NULL)
    {
        if ( token != NULL && (token->type == TOKEN_ROUTPUT 
            || token->type == TOKEN_DROUTPUT
            || token->type == TOKEN_RINPUT
            || token->type == TOKEN_DRINPUT))
            parse_redic(data, token);
        if (token != NULL && (token->type == TOKEN_EXP
            || token->type == TOKEN_DQUOTE
            || token->type == TOKEN_SINQTE
            || token->type == TOKEN_DOLLAR))
            parse_cmd(data, token, env);
        if (token->type == TOKEN_PIPE)
            data = parse_pipe(lsdata, data);
        if (token != NULL) 
            token = token->next;
    }
    if (data != NULL)
        ins_next_data(lsdata, data);
    if (lsdata->tail->prev != NULL && lsdata->tail->prev->pipe.statpipe != NUL)
        lsdata->tail->pipe.statpipe = END;
}