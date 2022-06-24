/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/24 02:59:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lstree.h"

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
        treend->utree.cmd.cmdarg = NULL;
        treend->utree.cmd.env = NULL;
        treend->utree.cmd.pathcmd = NULL;
        ins_next_tree(lstree, treend);
    }
    return (0);
}

int parse_cmd(t_lstree *lstree,t_token *token, char **env)
{
    t_tree  *treend;
    // char    *tmpexp;
    t_cmd   *cmd;
    int     size;

    // tmpexp = NULL;
    size = 0;
    ctreenode(lstree, CMD);
    treend = lstree->root;
    cmd = &treend->utree.cmd;
    if (cmd->pathcmd == NULL)
    {
        cmd->pathcmd = ft_which(token->value, env);
        cmd->env = env;
    }
    printf(" token => %s \n", token->value);
    if (cmd->cmdarg != NULL && token->value != NULL)
    {
        // while (cmd->cmdarg[len])
        // {
        //     tmpexp = ft_strjoinbis(tmpexp, " ");
        //     tmpexp = ft_strjoinbis(tmpexp, cmd->cmdarg[len++]);
        // }
        // tmpexp = ft_strjoinbis(tmpexp, " "); 
        // tmpexp = ft_strjoin(tmpexp, token->value);
        // cmd->cmdarg = ft_split(tmpexp, " ");
        size = ft_dstrlen(cmd->cmdarg);
        printf("size=> %d\n", size);
        cmd->cmdarg = (char **)ft_drealloc((void **) cmd->cmdarg,sizeof(char *) * (size + 1));
        // printf("here\n");
        cmd->cmdarg[size] = ft_strdup(token->value);
        cmd->cmdarg[size + 1] = NULL; 
    }
    else
        cmd->cmdarg = ft_split(token->value, " "); 
    // printf("temp => %s\n", cmd->cmdarg[0]);
    return (0);
}