/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 07:17:06 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int ctreenode(t_lstree *lstree, t_treetype type)
{
    t_tree      *treend;

    if (lstree->root == NULL || lstree->root->type != type) 
    {
        if(!(treend = malloc(sizeof(t_tree))))
            return (1);
        treend->type = type;
        treend->left = NULL;
        treend->right = NULL;
        treend->redic = malloc(sizeof(t_redicio));
        treend->redic->fd[0] = -1;
        treend->redic->fd[1] = -1; 
        treend->redic->name = NULL;
        treend->redic->numfile = 0; 
        ins_next_tree(lstree, treend);
        lstree->size += 1;
    }
    return (0);
}

t_token *parse_redic(t_lstree *lstree, t_token *token)
{
    t_tree      *treend;
    t_redicio   *redic;
    char        *dtaa;

    redic = NULL;
    ctreenode(lstree, REDICIO);
    treend = lstree->root;
    dtaa = NULL;
    if (treend->type == PIPE)
        redic = treend->right->redic;
    else
        redic = treend->redic;
    if (redic->name != NULL && token->value != NULL)
    {
        redic->numfile += 1;
        redic->name = ft_realloc((void *)redic->name,sizeof(t_file) * (redic->numfile + 1));
        redic->name[redic->numfile - 1].file = ft_strdup(token->value);
        dtaa = ft_strdup(token->value);
        redic->name[redic->numfile - 1].type = token->type;
        redic->name[redic->numfile].file = NULL;
    }
    else
    {
        redic->name = malloc(sizeof(t_file) * 2);
        redic->name[0].file = ft_strdup(token->value);
        dtaa = ft_strdup(token->value);
        redic->name[0].type = token->type;
        redic->name[1].file = NULL;
        redic->numfile += 1;
    }
    return (token);
}