/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/18 20:55:55 by sismaili         ###   ########.fr       */
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
	int		state;
	int		x;

	signal(SIGQUIT,handler);
	x = 0;
	len = 0;
	dt = data->head;
	if (!ft_strncmp(dt->cmd.cmdarg[0], "export", ft_strlen("export")))
	{
		ft_export(&dt->cmd);
		return ;	
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "unset", ft_strlen("unset")))
	{
			ft_unset(&dt->cmd);
			return ;
	}
	else if (!ft_strncmp(dt->cmd.cmdarg[0], "exit", ft_strlen("exit")))
	{
		write(1, "exit\n", 6);
		exit(0);
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
		waitpid(pid[x++], &state, 0);
	if (state == SIGINT)
		printf("\n");
	if (state == SIGQUIT)
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

	temp = lstok->head;
	while (temp)
	{
		check = ft_filter_token2(temp->value);
		if (check == -1)
			return (0);
		temp->value = search_var(temp->value, env, check);
		temp = temp->next;
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	// int		pid;
    t_lsnode	lstok;
	t_lexer		*lexer;
    char		*line;
	t_token		*token;
	t_lsdata	*lsdata;

	token = NULL;
	lsdata = NULL;
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1337)
	{
		gl.g_pid = 1;
		line = readline_t();
		gl.g_pid = 0;
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
			if (printtoken(&lstok))
			{
				if (delete_var(&lstok, env))
				{
					// printoken(&lstok);
					lsdata = malloc(sizeof(t_lsdata));
					init_lsdata(lsdata);
					parsing(lsdata, &lstok, env);
					// printall(lsdata);
					if (lsdata->head->cmd.cmdarg != NULL)
						recursive(lsdata);
				}
			}
		}
		//  ft_freetree(); 
	}
    return (0);
}
