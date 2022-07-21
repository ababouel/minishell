/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 00:50:25 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delete_var(t_lsnode *lstok, char **env)
{
	t_token *temp;
	int		check;
	char	*val;
	
	val = NULL;
	temp = lstok->head;
	while (temp)
	{
		check = ft_filter_token2(temp->value);
		if (check == -1)
			return (0);
		val = temp->value;
		temp->value = search_var(temp->value, env, check);
		if (temp->type == TOKEN_EXP)
			free(val);	
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char		*line;
    t_lsnode	lstok;
	t_lsdata	lsdata;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1337)
	{
		g_l.g_pid = 1;
		line = readline_t();
		g_l.g_pid = 0;
		add_history(line);
		if (!line)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
		if (line != NULL)
		{
			add_init_lstok(&lstok, line);
			if (printtoken(&lstok))
			{
				if (delete_var(&lstok, env))
				{
					init_lsdata(&lsdata);
					parsing(&lsdata, &lstok, env);
					if (lsdata.head->cmd.cmdarg != NULL)
						execution(&lsdata);
				}
				ft_freestack(&lstok);
				ft_freetree(&lsdata);
			}
			else
			{
				ft_freestackbis(&lstok);
				ft_freetree(&lsdata);
			}
			free (line);
		}
	}
    return (0);
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
