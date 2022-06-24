/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/24 02:29:07 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void    parsing(t_lstree *lstree, t_lsnode *lsnode, char **env)
{
    t_token *token;
    int     len;

    len = 0;
	token = lsnode->head; 
    while (token != NULL && token->type != TOKEN_EOL)
    {
        if (token->type == TOKEN_EXP
            || token->type == TOKEN_DQUOTE 
            || token->type == TOKEN_SINQTE
            || token->type == TOKEN_DOLLAR)
            parse_cmd(lstree, token, env);
        // if (token->type == TOKEN_PIPE)
        //     treend = parse_pipe();
        // if (token->type == TOKEN_ROUTPUT)
        //     treend = parse_routput();
        // if (token->type == TOKEN_DROUTPUT)
        //     treend = parse_droutput();
        // if (token->type == TOKEN_DRINPUT)
        //     treend = parse_drinput();
        // if (token->type == TOKEN_RINPUT)
        //     treend = parse_rinput();
        // printf("data track from => %d\n", token->type); 
        if (token->type != TOKEN_EOL) 
            token = token->next;
    }
    while (lstree->root->utree.cmd.cmdarg[len] !=  NULL)
    {
        printf("%s => cmdarg\n",lstree->root->utree.cmd.cmdarg[len]);
        len++; 
    }
}

void	init_lstree(t_lstree *lstree)
{
    lstree->root = NULL;
    lstree->size = 0;
}

int ins_next_tree(t_lstree *stack, t_tree *treend)
{
    t_tree  *temp;

    temp = NULL;
    if (treend->type == PIPE)
    {
        temp = stack->root;
        stack->root = treend;
        stack->root->left = temp;
    } 
    else if (treend->type == CMD)
    {
        if (stack->root == NULL)
            stack->root = treend;
        else if (stack->root->type == PIPE)
            stack->root->right = treend; 
    }
	return (0);
}
