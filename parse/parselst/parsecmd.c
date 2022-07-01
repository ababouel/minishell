/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 05:55:40 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lstree.h"

static int ctreenode(t_lstree *lstree, t_treetype type)
{
    t_tree  *treend;
    t_tree  *root;

    root = lstree->root;
    if (root == NULL 
        || (root->type == REDICIO &&(root->left == NULL || root->left->type != CMD))
        || (root->type == PIPE && (root->right == NULL || (root->right->type == REDICIO && root->right->left == NULL))))
    {
        if(!(treend = malloc(sizeof(t_tree))))
            return (1);
        treend->type = type;
        treend->left = NULL;
        treend->right = NULL;
        treend->cmd = malloc(sizeof(t_cmd));
        treend->cmd->cmdarg = NULL;
        treend->cmd->env = NULL;
        treend->cmd->pathcmd = NULL;
        ins_next_tree(lstree, treend);
        lstree->size += 1;
    }
    return (0);
}

int parse_cmd(t_lstree *lstree,t_token *token, char **env)
{
    t_tree  *treend;
    t_cmd   *cmd;
    int     size;

    size = 0;
    ctreenode(lstree, CMD);
    treend = lstree->root;
    if (treend->type == REDICIO)
        cmd = treend->left->cmd;
    else if (treend->type == PIPE)
    {
        treend = treend->right;
        if (treend->type == REDICIO)
            cmd = treend->left->cmd;
        else
            cmd = treend->cmd; 
    }
    else
        cmd = treend->cmd;
    if (cmd->pathcmd == NULL)
    {
        cmd->pathcmd = ft_which(token->value, env);
        cmd->env = env;
    }
    if (cmd->cmdarg != NULL && token->value != NULL)
    {
        size = ft_dstrlen(cmd->cmdarg);
        cmd->cmdarg = (char **)ft_drealloc((void **) cmd->cmdarg,sizeof(char *) * (size + 1));
        cmd->cmdarg[size - 1] = ft_strdup(token->value);
        cmd->cmdarg[size] = NULL; 
    }
    else
    {
        cmd->cmdarg = (char **)malloc(sizeof(char *) + 1);
        cmd->cmdarg[0] = token->value;
        cmd->cmdarg[1] = NULL;
    } 
    return (0);
}