/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 06:43:40 by ababouel         ###   ########.fr       */
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
        treend->utree.redic.fd = NULL;
        treend->utree.redic.name = NULL; 
        ins_next_tree(lstree, treend);
        lstree->size += 1;
    }
    return (0);
}

int parse_redic(t_lstree *lstree, t_lsnode *lsnode, char **env)
{
    t_tree      *treend;
    t_redicio   *redic;
    int         size;

    size = 0;
    ctreenode(lstree, REDICIO); 
}