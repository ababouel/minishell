/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/03 17:38:34 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// static int ctreenode(t_lstree *lstree, t_treetype type)
// {
//     t_tree  *treend;
//     t_tree  *root;

//     root = lstree->root;
//     if (root == NULL || root->type != type) 
//     {
//         if(!(treend = malloc(sizeof(t_tree))))
//             return (1);
//         treend->type = type;
//         treend->left = NULL;
//         treend->right = NULL;
//         treend->redic = malloc(sizeof(t_redicio));
//         treend->redic->fd[0] = -1;
//         treend->redic->fd[1] = -1; 
//         treend->redic->name = NULL;
//         treend->redic->numfile = 0; 
//         ins_next_tree(lstree, treend);
//         lstree->size += 1;
//     }
//     return (0);
// }

int parse_redic(t_data *data, t_token *token)
{
    t_cmd   *cmd;

    cmd = &data->cmd;
    if (cmd->name != NULL && token->value != NULL)
    {
        cmd->numfile += 1;
        cmd->name = ft_realloc((void *)cmd->name, sizeof(t_file) * (cmd->numfile + 1));
        cmd->name[cmd->numfile - 1].file = ft_strdup(token->value);
        cmd->name[cmd->numfile - 1].type = token->type;
        cmd->name[cmd->numfile].file = NULL;
    }
    else
    {
        cmd->name = malloc(sizeof(t_file) * 2);
        cmd->name[0].file = ft_strdup(token->value);
        cmd->name[0].type = token->type;
        cmd->name[1].file = NULL;
        cmd->numfile += 1;
    }
    return(0);
}