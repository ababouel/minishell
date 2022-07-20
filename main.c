/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/20 13:18:20 by ababouel         ###   ########.fr       */
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
	lsdata = NULL;	
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1337)
	{
		lstok = malloc(sizeof(t_lsnode));	
		lsdata = malloc(sizeof(t_lsdata));
		g_v.g_pid = 1;
		line = readline_t();
		// line = ft_strdup(av[2]);
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
			line = NULL;
			init_lsdata(lsdata);
			parsing(lsdata, lstok, env);
			if (lsdata->head->cmd.cmdarg != NULL)
				execution(lsdata);
			// break;
		}
		ft_freestack(lstok);
		ft_freetree(lsdata);
		free(lstok);
		free(lsdata);
	}
	// exit(0);
	// while(1){};
    return (0);
}