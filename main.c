/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:36:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/05/19 00:31:26 by ababouel         ###   ########.fr       */
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
	cmd = ft_calloc(0, sizeof(t_cmd));
	cmd->arg = ft_calloc(0 ,sizeof(char *) * 3);
	cmd->arg[1] = NULL;
	cmd->arg[0] = ft_strdup("ls adtdbhsdn");
	cmd->arg[2] = NULL;
	cmd->cmd = NULL;
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
		else if (token->type == TOKEN_OPTION || token->type == TOKEN_ARG)
		{
			if(path != NULL)
			{
				path = ft_realloc(path,(ft_strlen(path) + ft_strlen(token->value) + 1) * sizeof(char));
				ft_strcat(path, token->value);
			}
			else
				path = ft_strdup(token->value);
		}
		node = node->next;
	}
	cmd->arg[1] = path;
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
	line = "ls -l ";
    init_stack(&lstok);
    lexer = init_lexer(line);
	while((token = lexer_next_token(lexer))->type != TOKEN_EOL)
		ins_next_node(&lstok, (void *) token);
	cmd = init_cmd(&lstok, env);
	// printf("data\n");
	// printf("cmd =>%s\narg =>%s\n", cmd->cmd, cmd->arg[1]);
	if (execve(cmd->cmd, cmd->arg , env))
		perror("Error execve");
    return (0);
}



// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 		char cmd[] = "/bin/ls";
// 		if(execve(cmd, av , env) == -1)
// 			perror("Error execve");
// 	return (0);
// }