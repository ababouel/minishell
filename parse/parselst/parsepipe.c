/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:38:39 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/03 17:37:06 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// int parse_pipe(t_lstree *lstree)
// {
//     t_tree *tree;

//     tree = malloc(sizeof(t_tree));
//     if (!tree)
//         return (1);
//     tree->type = PIPE;
//     tree->left = NULL;
//     tree->right = NULL;
//     tree->pipe = malloc(sizeof(t_pipe));
//     tree->pipe->fd = malloc(sizeof(int) * 2);
//     piped(tree->pipe->fd);
//     ins_next_tree(lstree, tree);
//     return (0);  
// }

t_data  *parse_pipe(t_lsdata *lsdata, t_data *data)
{
    t_data  *new_dt;

    new_dt = NULL;
    piped(data->pipe.pfd);
    if (lsdata->size == 0)
        data->pipe.statpipe = START;
    else if (lsdata->size < (lsdata->nupipe - 1))
        data->pipe.statpipe = UPDATE;
    else if (lsdata->size == (lsdata->nupipe - 1))
        data->pipe.statpipe = END;
    ins_next_data(lsdata, data);
    new_dt = init_dt(data->cmd.env);
    return (new_dt);
}