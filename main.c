/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/19 13:57:03 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    char		*line;
    t_lsnode	*lstok;
	t_lsdata	*lsdata;
	
	lstok = NULL;	
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	lsdata = malloc(sizeof(t_lsdata));
	lstok = malloc(sizeof(t_lsnode));	
	while (1337)
	{
		g_v.g_pid = 1;
		line = readline_t();
		g_v.g_pid = 0;
		add_history(line);
		if (!line)
		{
			write(1, "exit\n", 5);
			free(lsdata);
			free(lstok);
			exit(0);
		}
		if (line != NULL)
		{	
			lstok = add_init_lstok(lstok, line);
			free(line);
			init_lsdata(lsdata);
			parsing(lsdata, lstok, env);
			ft_freestack(lstok);
			if (lsdata->head->cmd.cmdarg != NULL)
				execution(lsdata);
			ft_freetree(lsdata); 
		}
	}
    return (0);
}