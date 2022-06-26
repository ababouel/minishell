/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:38:39 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 06:24:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_tree  *parse_pipe()
{
    t_tree *tree;

    tree = malloc(sizeof(t_tree));
    if (!tree)
        return (NULL);
    tree->type = PIPE;
    tree->left = NULL;
    tree->right = NULL;
    piped(tree->utree.pipe.fd);

    return (tree);  
}