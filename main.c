/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/04 18:18:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	printall(t_lsdata *data)
// {
// 	int			x;
// 	int			y;
// 	int			z;
// 	t_data		*temp;
	
// 	x = 0;
// 	y = 0;
// 	temp = data->head;
// 	while (y < data->size)
// 	{
// 		if (temp != NULL)
// 		{
// 			if (temp->cmd.pathcmd != NULL)
// 				printf("path=>%s\n", temp->cmd.pathcmd);
// 			z = 0;
// 			while (temp->cmd.cmdarg != NULL && temp->cmd.cmdarg[z])
// 				printf("arg=>%s\n", temp->cmd.cmdarg[z++]);
// 		}
// 		x = 0;
// 		while (temp != NULL && temp->cmd.name != NULL && temp->cmd.name[x].file != NULL)
// 		{
// 			printf("filename=>%s\n", temp->cmd.name[x].file);
// 			x++;
// 		}
// 		if (temp != NULL)
// 		{
// 			temp = temp->next;
// 			y++;
// 		}
// 	}
// }

void	recursive(t_lsdata *data)
{
	t_data	*dt;

	dt = data->head;
	while (dt != NULL)
	{	
		built(dt);	
		if (dt != NULL)
			dt = dt->next;
	}
}

// void printoken(t_lsnode *lstok)
// {
// 	t_token	*tempnext;
// 	// t_token	*temprev;

// 	tempnext = lstok->head;
// 	// temprev = lstok->tail;
// 	while (tempnext)
// 	{
// 		printf("next token => %d => %s\n", tempnext->type, tempnext->value);
// 		tempnext = tempnext->next;
// 	}
// 	// while (temprev)
// 	// {
// 	// 	printf("prev token => %d => %s\n", temprev->type, temprev->value);
// 	// 	temprev = temprev->prev;
// 	// }
	
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
	t_lsdata	*lsdata;

	token = NULL;
	lsdata = NULL;	
	rl_catch_signals = 0;
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
			// printoken(&lstok);
			// if (lstok.head != NULL)
			// {
				lsdata = malloc(sizeof(t_lsdata));
				init_lstree(lsdata);
				parsing(lsdata, &lstok, env);
				// printall(lsdata);
				if (lsdata->head->cmd.cmdarg != NULL)
					recursive(lsdata); 
			// }
		//  ft_freetree(lsdata);
		// while(1); 
		}
	}
    return (0);
}