/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 09:26:11 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int ctreenode(t_lstree *lstree, t_treetype type)
{
    t_tree *treend;

    if (lstree->root == NULL || lstree->root->type != type) 
    {
        if(!(treend = malloc(sizeof(t_tree))))
            return (1);
        treend->type = type;
        treend->left = NULL;
        treend->right = NULL;
        treend->utree.redic.fd[0] = -1;
        treend->utree.redic.fd[1] = -1; 
        treend->utree.redic.name = NULL; 
        ins_next_tree(lstree, treend);
        lstree->size += 1;
    }
    return (0);
}

static int nufile(t_file *files)
{
    int x;

    x = 0;
    while (files[x].file != NULL)
        x++;
    return (x);
}

t_token *parse_redic(t_lstree *lstree, t_token *token)
{
    t_tree      *treend;
    t_redicio   *redic;
    int         size;

    size = 0;
    redic = malloc(sizeof(t_redicio));
    ctreenode(lstree, REDICIO);
    token = token->next;
    treend = lstree->root;
    redic = &treend->utree.redic;
    if (redic->name != NULL && token->value != NULL)
    {
        size = nufile(redic->name);
        redic->name = ft_realloc((void *)redic->name,sizeof(t_file) * (size + 1));
        redic->name[size - 1].file = ft_strdup(token->next->next->value);
        redic->name[size - 1].type = token->type;
        redic->name[size].file = NULL; 
    }
    else
    {
        redic->name = malloc(sizeof(t_file) + 1);
        while (token->type == TOKEN_SPACE)
            token = token->next;
        redic->name[0].file = ft_strdup(token->next->next->value);
        redic->name[0].type = token->type;
        redic->name[1].file = NULL;
    }
    return (token);
}