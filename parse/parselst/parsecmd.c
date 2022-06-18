/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/18 01:48:19 by ababouel         ###   ########.fr       */
=======
/*   Updated: 2022/06/17 22:11:29 by ababouel         ###   ########.fr       */
>>>>>>> 959f7b588f1bffda7aeb0b24207b7e2cf04e0450
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
    if (token->type == TOKEN_CMD)
        cmd.pathcmd = ft_which(token->value,env);
    while (temp != NULL)
    {
        token = (t_token *) temp->value;
        if ((token->type != TOKEN_CMD) && (token->type != TOKEN_ARG) && (token->type != TOKEN_OPTION))
            break;
        tmpstr = ft_strjoin(tmpstr, token->value);
        tmpstr = ft_strjoin(tmpstr, " ");
        if (temp != NULL)
            temp = temp->next;
    }
<<<<<<< HEAD
    // printf("=>%s\n", tmpstr);
=======
>>>>>>> 959f7b588f1bffda7aeb0b24207b7e2cf04e0450
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