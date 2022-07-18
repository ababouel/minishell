/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/18 16:56:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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

t_lsnode	*add_init_lstok(t_lsnode *lstok,char *line)
{
	t_lexer	*lexer;
	t_token	*token;

	lexer = NULL;
	token = NULL;	
	init_stack(lstok);
	lexer = init_lexer(line);
	while(lexer->i < ft_strlen(line))
	{
		if (lexer->src[lexer->i] != '\0')
			token = lexer_next_token(lexer);
		if (token != NULL)
			ins_next_node(lstok, (void *) token);
	}
	free(lexer);
	lexer = NULL;
	return (lstok);	
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
    t_lsnode	*lstok;
    char		*line;
	lstok = NULL;	
	t_lsdata	*lsdata;
	lsdata = malloc(sizeof(t_lsdata));
	lstok = malloc(sizeof(t_lsnode));	
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
				recursive(lsdata);
			ft_freetree(lsdata); 
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