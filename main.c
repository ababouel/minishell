/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/06 15:56:50 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printall(t_tree *treend)
{
	int			x;
	// t_redicio	*redic;	
	x = 0;

	while (treend->type == REDICIO && treend->redic != NULL && treend->redic->name[x].file != NULL)
	{
		printf("=>%s\n", treend->redic->name[x].file);
		x++;
	}
}

void	recursive(t_tree *lstree, int check)
{
	t_tree		*temp;
	int			x;
	// t_cmd		*cmd;
	// t_redicio	*redic;

	if (!lstree)
		return ;
	temp = lstree;
	x = 0;
	if (temp->left != NULL)
		recursive(temp->left, check);
	if (temp->type == PIPE)
		printf("%s\n", "|");
	if (temp->type == REDICIO)
	{
		while (x < temp->redic->numfile)
			printf("redic=> %s\n", temp->redic->name[x++].file);
	}
	if (temp->right != NULL)
		recursive(temp->right, check);
	if (temp->type == CMD)
	{
		built(lstree->cmd);
		// while (temp->cmd->cmdarg[x] != NULL)
		// 	printf("%s ", temp->cmd->cmdarg[x++]);
		// printf("\n");
	}
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

void	delete_var(t_lsnode *lstok, char **env, int check)
{
	t_token *temp;

	temp = lstok->head;
	while (temp)
	{
		temp->value = search_var(temp->value, env, check);
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
	int			check;

	token = NULL;
	lstree = NULL;	
	// rl_catch_signals = 0;
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
			if (printtoken(&lstok))
			{
				check = ft_filter_token(&lstok, env);
				delete_var(&lstok, env, check);
				lstree = malloc(sizeof(t_lstree));
				init_lstree(lstree);
				parsing(lstree, &lstok, env);
				recursive(lstree->root, check);
			}
		}
		 ft_freetree(&lstree); 
	}
    return (0);
}
