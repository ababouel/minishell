/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/23 02:02:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lstree.h"

t_tree  *parse_cmd(t_token *token, char **env)
{
    t_cmd   cmd;
    t_tree  *treend;
    char    *tmpexp;
    char    *tmpqte;
    

    tmpexp = " ";
    tmpqte = NULL;
    treend = NULL;
    cmd.pathcmd = ft_which(token->value,env);
    while (token != NULL && token->type != TOKEN_EOL)
    {
        if (token->type == TOKEN_EXP)
        {
            tmpexp = ft_strjoin(tmpexp, token->value);
            tmpexp = ft_strjoin(tmpexp, " ");
        }
        if ((token->type == TOKEN_DQUOTE || token->type == TOKEN_SINQTE) 
            && token->value != NULL)
            {
                tmpqte = ft_strjoin(tmpqte, token->value);
                tmpqte = ft_strjoin(tmpqte, " ");
            }
        if (token != NULL)
            token  = token->next;
    }
    printf("tmpexp=>%s\n",tmpexp);
    printf("tmpqte=>%s\n",tmpqte);
    cmd.cmdarg = ft_split(tmpexp, " ");
    if (tmpqte != NULL)
    {
        cmd.cmdarg = (char **)ft_drealloc((void **)cmd.cmdarg, sizeof(char *) * (ft_dstrlen(cmd.cmdarg) + 1));
        cmd.cmdarg[ft_dstrlen(cmd.cmdarg)] = tmpqte;
    }
    printf("%s => qte\n",cmd.cmdarg[ft_dstrlen(cmd.cmdarg) - 1]);
    cmd.env = env;
    if(!(treend = malloc(sizeof(t_tree))))
        return (NULL);
    treend->utree.cmd = cmd;
    treend->type = CMD;
    treend->left = NULL;
    treend->right = NULL;
    return (treend);
}