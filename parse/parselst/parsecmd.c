/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:27:57 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/06 19:31:25 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lstree.h"

void	parse_cmd(t_data *data, t_token *token, char **env)
{
	int		size;
	t_cmd	*cmd;

	size = 0;
	cmd = &data->cmd;
	if (cmd->pathcmd == NULL)
	{
		cmd->pathcmd = ft_which(token->value, env);
		cmd->env = env;
		cmd->export = cmd->env;
	}
	if (cmd->cmdarg != NULL && token->value != NULL)
	{
		size = ft_dstrlen(cmd->cmdarg);
		cmd->cmdarg = (char **)ft_drealloc((void **) cmd->cmdarg,
				sizeof(char *) * (size + 1));
		cmd->cmdarg[size - 1] = ft_strdup(token->value);
		cmd->cmdarg[size] = NULL;
	}
	else
	{
		cmd->cmdarg = (char **)malloc(sizeof(char *) + 1);
		cmd->cmdarg[0] = ft_strdup(token->value);
		cmd->cmdarg[1] = NULL;
	}
}
