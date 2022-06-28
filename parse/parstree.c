/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/28 01:05:23 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void    parsing(t_lstree *lstree, t_lsnode *lsnode, char **env)
{
    t_token *token;

	token = lsnode->head; 
    while (token != NULL)
    {
        if ( token != NULL && (token->type == TOKEN_ROUTPUT 
            || token->type == TOKEN_DROUTPUT
            || token->type == TOKEN_RINPUT
            || token->type == TOKEN_DRINPUT))
        {
            parse_redic(lstree, token);
            token = token->next->next->next;
        }
        if (token != NULL && 
            (token->type == TOKEN_EXP
            || token->type == TOKEN_DQUOTE 
            || token->type == TOKEN_SINQTE
            || token->type == TOKEN_DOLLAR))
            parse_cmd(lstree, token, env);
        // if (token->type == TOKEN_PIPE)
        //     treend = parse_pipe();
        // if (token->type == TOKEN_RINPUT)
        //     treend = parse_rinput();
        // printf("data track from => %d\n", token->type); 
        if (token != NULL) 
            token = token->next;
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
        treend->left = temp;
    }
    else if (treend->type == REDICIO)
    {
        if (stack->root == NULL)
            stack->root = treend;
        if (stack->root->type == CMD)
        {
            temp = stack->root;
            stack->root = treend;
            treend->left = temp;
        }
        else if (stack->root->type == PIPE)
            stack->root->right = treend;
    } 
    else if (treend->type == CMD)
    {
        if (stack->root == NULL)
            stack->root = treend;
        else if (stack->root->type == REDICIO)
            stack->root->left = treend;
        else if (stack->root->type == PIPE)
            stack->root->right = treend; 
    }
	return (0);
}

// t_lsnode    parsing(t_lsnode *lsnode, char **env)
// {
//     t_lsnode    node; 
// }