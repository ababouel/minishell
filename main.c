/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/28 15:56:09 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minishell.h"
	
void	printall(t_tree *treend)
{
	int x;

	x = 0;
	while (treend->utree.redic.name[x].file)
	{
		printf("=>%s\n", treend->utree.redic.name[x].file);
		x++;
	}
}

void	recursive(t_tree *lstree)
{
	t_tree	*temp;

	temp = lstree;
	if (temp->left != NULL)
		recursive(temp->left);
	if (temp->type == PIPE)
		printf("%s\n", "PIPE");
	if (temp->type == REDICIO)
		printall(temp);
	if (temp->type == DAND)
		printf("%s\n", "DAND");
	if (temp->type == DPIPE)
		printf("%s\n", "DPIPE");
	if (temp->right != NULL)
		recursive(temp->right);
	if (temp->type == CMD)
		built(&lstree->utree.cmd);
}

// void printtoken(t_lsnode *lstok)
// {
// 	t_token	*temp;

// 	temp = lstok->head;
// 	while (temp)
// 	{
// 		printf("data => %d => %s\n", temp->type, temp->value);
// 		temp = temp->next;
// 	}
// }

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
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
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minihell$ ");
		add_history(line);
		if (!line)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		if (line != NULL && ft_strlen(line) > 0)
		{
			init_stack(&lstok);
			lexer = init_lexer(line);
			while((token = lexer_next_token(lexer))->type != TOKEN_EOL)
			{
				if (token != NULL)
					ins_next_node(&lstok, (void *) token);
			}
			if (printtoken(&lstok))
			{
				parsing(lstree, &lstok, env);
				recursive(lstree->root);
			}
		}
		ft_freetree(lstree);
	}
    return (0);
}
