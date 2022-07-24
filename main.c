/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:14:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/24 17:18:48 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exitcheck(t_env *env, char *line)
{
	if (!line)
	{
		write(1, "exit\n", 5);
		// env = ft_freedt(env);
		env = NULL;
		return (1);
	}
	return (0);
}

static void	loop_line(t_env *env, char *line)
{
	t_lsnode	lstok;
	t_lsdata	lsdata;

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
	t_env	*tenv;
	char	*line;

	(void) av;
	(void) ac;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	tenv = malloc(sizeof(t_env));
	g_l.export = malloc(sizeof(t_env));
	dup_envis(tenv, env);
	dup_envis(g_l.export, env);
	g_l.env = env;
	while (1337)
	{
		g_l.g_pid = 1;
		line = readline_t();
		g_l.g_pid = 0;
		add_history(line);
		if (exitcheck(tenv, line))
			exit(0);
		loop_line(tenv, line);
	}
	return (0);
}
