/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/28 04:49:55 by ababouel         ###   ########.fr       */
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

void printoken(t_lsnode *lstok)
{
	t_token	*tempnext;
	t_token	*temprev;

	tempnext = lstok->head;
	temprev = lstok->tail;
	while (tempnext)
	{
		printf("next token => %d => %s\n", tempnext->type, tempnext->value);
		tempnext = tempnext->next;
	}
	// while (temprev)
	// {
	// 	printf("prev token => %d => %s\n", temprev->type, temprev->value);
	// 	temprev = temprev->prev;
	// }
	
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
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minihell$ ");
		add_history(line);
		if (!line)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		if (line != NULL)
		{
			init_stack(&lstok);
			lexer = init_lexer(line);
			while(lexer->i < ft_strlen(line))
			{
				if (lexer->src[lexer->i] != '\0')
					token = lexer_next_token(lexer);
				if (token != NULL)
					ins_next_node(&lstok, (void *) token);
			}
			printoken(&lstok);
			// if (printtoken(&lstok))
			// {
				// parsing(lstree, &lstok, env);
				// // printall(lstree->root);
				// recursive(lstree->root);
			// }
		}
		ft_freetree(lstree);
	}
    return (0);
}
