/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/24 04:39:28 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minishell.h"
	
void	recursive(t_tree *lstree)
{
	t_tree	*temp;

	temp = lstree;
	if (temp->left != NULL)
		recursive(temp->left);
	if (temp->type == PIPE)
		printf("%s\n", "PIPE");
	if (temp->type == ROUTPUT)
		printf("%s\n", "ROUTPUT");
	if (temp->type == DROUTPUT)
		printf("%s\n", "DROUTPUT");
	if (temp->type == RINPUT)
		printf("%s\n", "RINPUT");
	if (temp->type == DRINPUT)
		printf("%s\n", "DRINPUT");
	if (temp->type == DAND)
		printf("%s\n", "DAND");
	if (temp->type == DPIPE)
		printf("%s\n", "DPIPE");
	if (temp->right != NULL)
		recursive(temp->right);
	if (temp->type == CMD)
		exec_cmd(&(temp->utree.cmd));
}

void printtoken(t_lsnode *lstok)
{
	t_token	*temp;

	temp = lstok->head;
	while (temp)
	{
		printf("data => %d => %s\n", temp->type, temp->value);
		temp = temp->next;
	}
}

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
		if ((line = readline("minihell$ ")) != NULL)
		{
			init_stack(&lstok);
			lexer = init_lexer(line);
			while((token = lexer_next_token(lexer))->type != TOKEN_EOL)
			{
				if (token != NULL)
					ins_next_node(&lstok, (void *) token);
			}

			//  printtoken(&lstok);
			parsing(lstree, &lstok, env);
			recursive(lstree->root);
		}
		ft_freetree(lstree);
	}
    return (0);
}
