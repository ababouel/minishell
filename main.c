/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/22 16:03:47 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_cmd
{
	char *cmd;
	char **arg;
	char **env;
}	t_cmd;

t_cmd	*init_cmd(t_lsnode *lsnode, char **env)
{
	t_cmd	*cmd;
	t_node	*node;
	t_token *token;
	char	*path;

	token = NULL;
	path = NULL;
	node = lsnode->head;
	cmd = ft_calloc(1, sizeof(t_cmd));
	cmd->arg = ft_calloc(4 ,sizeof(char *));
	cmd->arg[0] = ft_strdup("");
	cmd->env = env;
	while (node)
	{
		token = (t_token *) node->value;
		if (token->type == TOKEN_CMD)
		{
			cmd->cmd = ft_strdup("/bin/");
			cmd->cmd = ft_realloc(cmd->cmd,(ft_strlen(cmd->cmd) + ft_strlen(token->value) + 1) * sizeof(char));
			ft_strcat(cmd->cmd, token->value);
		}
		else if (token->type == TOKEN_ARG)
			cmd->arg[2] = ft_strdup(token->value);
		else if (token->type == TOKEN_OPTION)
			cmd->arg[1] = ft_strdup(token->value);
		node = node->next;
	}
	
	return (cmd);
}



int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
    t_lsnode	lstok;
	t_lexer		*lexer;
    char		*line;
	t_node 		*node;
	t_token		*token;
	t_cmd		*cmd;

	token = NULL;
	node = NULL;
	line = "echo 'LOGNAME' ";
    init_stack(&lstok);
    lexer = init_lexer(line);
	while((token = lexer_next_token(lexer, &lstok))->type != TOKEN_EOL)
		ins_next_node(&lstok, (void *) token);
    return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	int x;
// 	x = 0;
// 	(void)ac;
// 		char cmd[] = "/bin/ls";
// 		while (av[x])
// 		{
// 			printf("av[%d]=>%s\n", x, av[x]);
// 			x++;
// 		}
// 		if(execve(cmd, av , env) == -1)
// 			perror("Error execve");
// 	return (0);
// }