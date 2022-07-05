/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/05 20:22:28 by ababouel         ###   ########.fr       */
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
	int		pid[1000];
	int		len;
	int		x;

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
		waitpid(pid[x++], NULL, 0);
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
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1337)
	{
		line = readline_t();
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
				init_lsdata(lsdata);
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