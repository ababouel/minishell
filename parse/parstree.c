/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/18 20:56:59 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void    parsing(t_lstree *lstree, t_lsnode *lsnode, char **env)
{
    t_node 	*temp;
    t_token *token;
    t_tree  *treend;

    temp = lsnode->head; 
	token = NULL;
    treend = NULL;
    while (temp)
    {
		token = (t_token *) temp->value;
        if (token->type == TOKEN_CMD)
            treend = parse_cmd(token, env, temp);
        if(token->type == TOKEN_PIPE)
            treend = parse_pipe();
        if (treend != NULL)
           ins_next_tree(lstree, (void *) treend); 
        if (temp != NULL) 
            temp = temp->next;
    }
}

void	init_lstree(t_lstree *lstree)
{
    lstree->root = NULL;
    lstree->size = 0;
}

int ins_next_tree(t_lstree *stack, void *data)
{
    t_tree  *treend;
    t_tree  *temp;

    treend = (t_tree *) data;
    temp = NULL;
    if (treend->type == PIPE)
    {
        temp = stack->root;
        stack->root = treend;
        stack->root->left = temp;
    }
    else if (treend->type == DROUTPUT)
    {
        
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
