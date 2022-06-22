/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/22 22:55:46 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_tree  *parse_cmd(t_token *token, char **env)
{
    t_cmd   cmd;
    t_tree  *treend;
    char    *tmpstr;
    char    

    tmpstr = " ";
    treend = NULL;
    cmd.pathcmd = ft_which(token->value,env);
    while ( token != NULL && token->type != TOKEN_EOL)
    {
        if (token->type == TOKEN_EXP)
        {
            tmpstr = ft_strjoin(tmpstr, token->value);
            tmpstr = ft_strjoin(tmpstr, " ");
        }
        if ((token->type == TOKEN_DQUOTE || token->type == TOKEN_SINQTE) 
            && token->value != NULL)
            {
                printf("quote=> %s\n")
                tmpstr = ft_strjoin(tmpstr, token->value);
                tmpstr = ft_strjoin(tmpstr, " ");
            }
        if (token != NULL)
            token  = token->next;
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