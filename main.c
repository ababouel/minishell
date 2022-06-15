/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/15 01:24:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
    t_lsnode	lstok;
	t_lexer		*lexer;
    char		*line;
	t_node 		*node;
	t_token		*token;

	token = NULL;
	node = NULL;
	while (1337)
	{
		if((line = readline("minihell$ ")) != NULL)
		{
			init_stack(&lstok);
			lexer = init_lexer(line);
			while((token = lexer_next_token(lexer, &lstok))->type != TOKEN_EOL)
			{
				if (token != NULL)
				ins_next_node(&lstok, (void *) token);
			}
			node = lstok.head;
			while (node)
			{
				token = (t_token *) node->value;
				printf("%d => %s\n", token->type,token->value);
				node = node->next;
			}
		}
	}
    return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	int x;
// 	x = 0;
// 	(void)ac;
// 		char cmd[] = "/bin/ls";
// 		while (av[x])
// 		{
// 			printf("av[%d]=>%s\n", x, av[x]);
// 			x++;
// 		}
// 		if(execve(cmd, av , env) == -1)
// 			perror("Error execve");
// 	return (0);
// }