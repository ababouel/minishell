/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parstree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:52:26 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/26 19:10:54 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lstree.h"

void	init_lstree(t_lstree *lstree)
{
    lstree->root = NULL;
    lstree->size = 0;
}

int		parsing(t_lstree *lstree, t_lsnode *lsnode)
{
    t_node 	*node;
    t_token	*token;
	t_node	*node;

    node = lsnode->head;
	token = NULL;
    while (node)
    {
		token = (t_token *) node->value;
        if (token->type == TOKEN_CMD)			
    }
}
