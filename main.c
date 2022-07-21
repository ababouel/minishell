/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:14:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 16:00:52 by sismaili         ###   ########.fr       */
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

char	**dup_env(char **env)
{
	char	**temp_env;
	int		i;

	i = 0;
	while(env[i])
		i++;
	temp_env = malloc(sizeof(char *) * (i + 1));
	if (!temp_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		temp_env[i] = ft_strdup(env[i]);
		i++;
	}
	temp_env[i] = NULL;
	return (temp_env);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char		*line;
    t_lsnode	lstok;
	t_lsdata	lsdata;
	char		**d_env;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	d_env = dup_env(env);
	while (1337)
	{
		g_l.g_pid = 1;
		line = readline_t();
		g_l.g_pid = 0;
		add_history(line);
		if (!line)
		{
			write(1, "exit\n", 5);
			d_env = ft_freedt(d_env);
			exit(0);
		}
		if (line != NULL)
		{
			add_init_lstok(&lstok, line);
			if (printtoken(&lstok))
			{
				// printoken(&lstok);
				if (delete_var(&lstok, d_env))
				{
					init_lsdata(&lsdata);
					parsing(&lsdata, &lstok, d_env);
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
