/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:38:39 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 03:33:14 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int parse_pipe(t_lstree *lstree)
{
    t_tree *tree;

    tree = malloc(sizeof(t_tree));
    if (!tree)
        return (1);
    tree->type = PIPE;
    tree->left = NULL;
    tree->right = NULL;
    tree->pipe = malloc(sizeof(t_pipe));
    tree->pipe->fd = malloc(sizeof(int) * 2);
    piped(tree->pipe->fd);
    ins_next_tree(lstree, tree);
    return (0);  
}