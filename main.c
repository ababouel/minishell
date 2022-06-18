/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/18 19:01:22 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minishell.h"

void	recursive(t_tree *lstree)
{
	t_tree	*temp;

	temp = lstree;

	if (temp->type == PIPE)
		printf("%s\n", "PIPE");
	if (temp->type == CMD)
		printf("%s\n", temp->utree.cmd.cmdarg[0]);
	if (temp->left != NULL)
		recursive(temp->left);
	if (temp->right != NULL)
		recursive(temp->right);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    t_lsnode	lstok;
	t_lexer		*lexer;
    char		*line;
	t_token		*token;
	t_lstree	*lstree;

	token = NULL;
	lstree = malloc(sizeof(t_lstree));
	init_lstree(lstree);
	while (1337)
	{
		if ((line = readline("minihell$ ")) != NULL)
		{
			init_stack(&lstok);
			lexer = init_lexer(line);
			while((token = lexer_next_token(lexer, &lstok))->type != TOKEN_EOL)
			{
				if (token != NULL)
					ins_next_node(&lstok, (void *) token);
			}
			parsing(lstree, &lstok, env);
			recursive(lstree->root);
			// exec_cmd(&(lstree->root->utree.cmd));	
		}
		ft_freetree(lstree);
	}
    return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	int x;
// 	char *cmd;
// 	x = 0;
// 	(void)ac;
	
// 		cmd = ft_which(av[1], env);
// 		// printf("path %s = %s\n", av[1], cmd);
// 		// while (av[x])
// 		// {
// 		// 	printf("av[%d]=>%s\n", x, av[x]);
// 		// 	x++;
// 		// }
// 		if(execve(cmd, &av[1] , env) == -1)
// 			perror("Error execve");
// 	return (0);
// }