/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/21 02:59:00 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void printoken(t_lsnode *lstok)
{
	t_token	*tempnext;
	// t_token	*temprev;

	tempnext = lstok->head;
	// temprev = lstok->tail;
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

void	recursive(t_lsdata *data)
{
	t_data	*dt;
	int		pid[1000];
	int		len;
	int		x;

	signal(SIGQUIT,handler);
	x = 0;
	len = 0;
	dt = data->head;
	if (!ft_strncmp(dt->cmd.cmdarg[0], "export", ft_strlen("export")))
	{
		g_l.state = ft_export(&dt->cmd);
		return ;
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "unset", ft_strlen("unset")))
	{
			g_l.state = ft_unset(&dt->cmd);
			return ;
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "exit", ft_strlen("exit")))
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	else if (dt->cmd.pathcmd != NULL && !ft_strncmp(dt->cmd.pathcmd, "/usr/bin/cd", ft_strlen(dt->cmd.pathcmd)))
	{
		g_l.state = ft_cd(&dt->cmd);
		return ;
	}
	else if (dt->cmd.pathcmd != NULL && !ft_strncmp(dt->cmd.pathcmd, "/usr/bin/env", ft_strlen(dt->cmd.pathcmd)))
	{
		g_l.state = ft_env(&dt->cmd);
		return ;
	}
	while (dt != NULL)
	{
		pid[len] = forcked();
		if (pid[len] == 0)
			built(dt, data);
		if (pid[len] > 0)
			redic_close(&dt->cmd);
		if (dt != NULL)
			dt = dt->next;
		len++;
	}
	dt = data->head;
	ft_stat_pipe_close(dt);
	while(x < len)
	{
		waitpid(pid[x++], &g_l.state, 0);
		if (WIFEXITED(g_l.state))
			g_l.state = WEXITSTATUS(g_l.state);
	}
	if (g_l.state == SIGINT)
		printf("\n");
	if (g_l.state == SIGQUIT)
		printf("Quit: 3\n");
	signal(SIGQUIT,SIG_IGN);
}

char    *readline_t(void)
{
    char            *buf;
    struct termios    attr;
    struct termios    old_attr;

    tcgetattr(STDIN_FILENO, &old_attr);
    attr = old_attr;
    attr.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &attr);
    buf = readline("minishell$ ");
    tcsetattr(STDIN_FILENO, TCSANOW | TCSAFLUSH, &old_attr);
    return (buf);
}

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
		// free (val);
		// if (val != NULL)
		// 	free(val);
		// val = NULL;
		temp = temp->next;
	}
	return (1);
}

void	ft_freestackbis(t_lsnode *sk)
{
	t_token	*node;
	t_token	*temp;

	node = sk->head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		if (temp->type == TOKEN_EXP)
			free(temp->value);
		temp->value = NULL;
		free(temp);
		temp = NULL;
	}
	init_stack(sk);
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
	t_lsdata	lsdata;

	token = NULL;
	// lsdata = NULL;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1337)
	{
		g_l.g_pid = 1;
		line = readline_t();
		// line = av[2];
		g_l.g_pid = 0;
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
					ins_next_node(&lstok, (void *)token);
			}
			free(lexer);
			lexer = NULL;
			int	test;
			test = printtoken(&lstok);
			if (test && test != 3)
			{
				// printoken(&lstok);
				if (delete_var(&lstok, env))
				{
					// printoken(&lstok);
					// lsdata = malloc(sizeof(t_lsdata));
					init_lsdata(&lsdata);
					parsing(&lsdata, &lstok, env);
					// printall(lsdata);
					if (lsdata.head->cmd.cmdarg != NULL)
						recursive(&lsdata);
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
			// break;
		}
		//  ft_freetree(); 
	}
    return (0);
}
