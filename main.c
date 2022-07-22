/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:14:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/22 22:09:33 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exitcheck(char **env, char *line)
{
	if (!line)
	{
		write(1, "exit\n", 5);
		env = ft_freedt(env);
		return (1);
	}
	return (0);
}

static void	loop_line(char **env, char *line)
{
	t_lsnode	lstok;
	t_lsdata	lsdata;

	(void)env;
	if (line != NULL)
	{
		add_init_lstok(&lstok, line);
		init_lsdata(&lsdata);
		if (printtoken(&lstok))
		{
			if (delete_var(&lstok, env))
			{	
				parsing(&lsdata, &lstok, env);
				if (lsdata.head->cmd.name || lsdata.head->cmd.cmdarg != NULL)
					execution(&lsdata);
			}
		}
		ft_freestackbis(&lstok);
		ft_freetree(&lsdata);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	char	**d_env;
	char	*line;

	(void) av;
	(void) ac;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	d_env = dup_env(env);
	g_l.export = env;
	while (1337)
	{
		g_l.g_pid = 1;
		line = readline_t();
		g_l.g_pid = 0;
		add_history(line);
		if (exitcheck(d_env, line))
			exit(0);
		loop_line(d_env, line);
	}
	return (0);
}
