/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/18 00:02:47 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    t_lsnode	lstok;
	t_lexer		*lexer;
    char		*line;
	t_node 		*node;
	t_token		*token;
	line = "ls	-la	| grep	$(philipe) >> data | wc -l";
    init_stack(&lstok);
    lexer = init_lexer(line);
	token = NULL;
	node = NULL;
	while((token = lexer_next_token(lexer))->type != TOKEN_EOL)
		ins_next_node(&lstok, (void *) token);
	node = lstok.head;
	while (node)
	{
		token =(t_token *) node->value;
		printf("type => %d\n", (int)token->type);
		printf("value => %s\n", token->value);
		node = node->next;
	}
    return (0);
}