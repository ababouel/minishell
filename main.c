/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/15 01:04:07 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    t_lsnode	lstok;
    char		*line;
	t_node 		*node;
	t_token		*token;
	line = "ls	-la	|	grep	$(philipe) >> data	| \n wc -l";
    init_stack(&lstok);
    init_lexer(line, &lstok);
	node = lstok.head;
	while (node)
	{
		token =(t_token *) node->value;
		printf("type => %s\n", token->type);
		printf("value => %s\n", token->value);
		node = node->next;
	}
    return (0);
}