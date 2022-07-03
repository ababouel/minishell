/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/03 17:51:44 by ababouel         ###   ########.fr       */
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

t_data  *init_dt(char **env)
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->cmd.ffd[0] = -1;
    data->cmd.ffd[1] = -1;
    data->pipe.pfd[1] = -1;
    data->pipe.pfd[0] = -1;
    data->cmd.numfile = 0;
    data->cmd.name = NULL;
    data->cmd.cmdarg = NULL;
    data->cmd.pathcmd = NULL;
    data->cmd.env = env;
    data->pipe.statpipe = NUL;
    return (data);
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
    ins_next_data(lsdata, data);  
}

void	init_lstree(t_lsdata *t_lsdata)
{
    t_lsdata->head = NULL;
    t_lsdata->tail = NULL;
    t_lsdata->size = 0;
}

int ins_next_data(t_lsdata *stack, t_data *data)
{
	t_data	*temp;
	
	if (stack->head == NULL)
	{
		stack->head = data;
		stack->tail = data;
		stack->head->next = NULL;
		stack->head->prev = NULL;
	}
	else
	{
		temp = stack->head;
		while (temp->next)
			temp = temp->next;	
		temp->next = data;
		temp->next->prev = temp;
		stack->tail = data;
	}
	stack->size++;
	return (0);
}
