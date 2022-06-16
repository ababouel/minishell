/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 20:05:01 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/exec.h"

t_tree  *parse_cmd(t_token *token, char **env, t_node *temp)
{
    t_cmd   cmd;
    t_tree  *treend;
    char    *tmpstr;

    tmpstr = " ";
    treend = NULL;
    cmd.pathcmd = ft_which(token->value,env);
    while (temp != NULL && (token->type == TOKEN_CMD || token->type == TOKEN_ARG || token->type == TOKEN_OPTION))
    {
        token = (t_token *) temp->value;
        tmpstr = ft_strjoin(tmpstr, token->value);
        tmpstr = ft_strjoin(tmpstr, " ");
        if (temp != NULL)
            temp = temp->next;
    }
    cmd.cmdarg = ft_split(tmpstr, " ");
    cmd.env = env;
    if(!(treend = malloc(sizeof(t_tree))))
        return (NULL);
    treend->utree.cmd = cmd;
    treend->type = CMD;
    treend->left = NULL;
    treend->right = NULL;
    return (treend);
}