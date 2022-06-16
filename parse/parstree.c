/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 02:49:23 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lstree.h"
#include "../inc/exec.h"


void    parsing(t_lstree *lstree, t_lsnode *lsnode, char **env)
{
    t_node 	*temp;
    t_token *token;
    t_cmd   cmd;
    char    *tmpstr;
    t_tree  *treend;

    temp = lsnode->head;
	token = NULL;
    tmpstr = " ";
    treend = NULL;
    while (temp)
    {
        treend = malloc(sizeof(t_tree));
		token = (t_token *) temp->value;
        if (token->type == TOKEN_CMD)
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
        treend->utree.cmd = cmd;
        treend->left = NULL;
        treend->right = NULL;
        lstree->root = treend;
        lstree->size += 1;
        if (temp != NULL) 
            temp = temp->next;
    }
}

void	init_lstree(t_lstree *lstree)
{
    lstree->root = NULL;
    lstree->size = 0;
}

int ins_next_tree(t_lstree *stack, void *data)
{
	t_tree	*new_node;
	t_tree	*temp;
	
	temp = NULL;
	new_node = calloc(1,sizeof(t_tree));
	if (new_node == NULL)
		return (-1);
	new_node->utree.cmd = *(t_cmd *) data;
	new_node->left = NULL;
    new_node->right = NULL;
	if (stack->root == NULL)
		stack->root = new_node;
	else
	{
		temp = stack->root;
		while (temp->left)
			temp = temp->left;	
		temp->left = new_node;
	}
	stack->size++;
	return (0);
}

// t_cmd	parse_cmd(char *path, char **arg, char **env)
// {
//     t_cmd *cmd;

//     cmd = NULL;
//     cmd = malloc(sizeof(t_cmd));
//     cmd->pathcmd = path;
//     cmd->cmdarg = arg;
//     cmd->env = env;
//     return cmd;
// }
