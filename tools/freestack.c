/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:35:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/01 06:38:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "lstree.h"

void	ft_freestack(t_lsnode *sk)
{
	t_token	*node;
	t_token *temp;
	
	node = sk->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(node->value);
		free(temp);
	}
	// free(sk);
}

void	ft_freetree(t_lstree **sk)
{
	t_tree	*node;
	// t_cmd	*cmd;
	// t_file 	*file;
	// char 	*filedata;
	// char 	**cmdarg;
	if (!sk || !*sk)
		return ;
	while ((*sk)->root != NULL)
	{
		node = (*sk)->root;
		// if (sk->root->type == CMD)
		// {
		// 	cmdarg = sk->root->cmd->cmdarg;
		// 	cmd  = sk->root->cmd;
		// 	free(cmdarg);
		// 	free(cmd);
		// }
		// else if (sk->root->type == REDICIO)
		// {
		// 	file = sk->root->redic->name;
		// 	filedata = sk->root->redic->name->file;
		// 	free(filedata);
		// 	free(file);
		// 	free(sk->root->redic);
		// }
		(*sk)->root = (*sk)->root->left;
		free(node);
	}
	free(*sk);
	*sk = NULL;	
}