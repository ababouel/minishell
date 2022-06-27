/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/27 21:17:59 by ababouel         ###   ########.fr       */
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
        treend->utree.redic = malloc(sizeof(t_redicio));
        treend->utree.redic->fd[0] = -1;
        treend->utree.redic->fd[1] = -1; 
        treend->utree.redic->name = NULL;
        treend->utree.redic->numfile = 0; 
        ins_next_tree(lstree, treend);
        lstree->size += 1;
    }
    return (0);
}

// static int nufile(t_file *files)
// {
//     int x;

//     x = 0;
//     while (files[x].file != NULL)
//         x++;
//     return (x);
// }

t_token *parse_redic(t_lstree *lstree, t_token *token)
{
    t_tree      *treend;
    t_redicio   *redic;
    int  size;

    size = 0;
    // printf("type =>%d\n", token->type);
    ctreenode(lstree, REDICIO);
    // printf("tree type =>%d\n", lstree->root->type);
    token = token->next;
    treend = lstree->root;
    redic = treend->utree.redic;
    if (redic->name != NULL && token->value != NULL)
    {
        size = redic->numfile + 1;
        redic->name = ft_realloc((void *)redic->name, sizeof(t_file) * (redic->numfile));
        while (token->type == TOKEN_SPACE)
            token = token->next;
        redic->name[size - 1].file = token->value;
        redic->name[size - 1].type = token->type;
        redic->name[size].file = NULL;
        printf("size =>%d\n", size);
        redic->numfile += 1;
    }
    else
    {
        redic->name = malloc(sizeof(t_file) + 1);
        while (token->type == TOKEN_SPACE)
            token = token->next;
        redic->name[0].file = token->value;
        redic->name[0].type = token->type;
        redic->name[1].file = NULL;
        // redic->numfile += 1;
    }
    return (token);
}