/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:11:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/19 13:07:43 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

void	redic_close(t_cmd *cmd)
{
	if (cmd->ffd[1] > 0)
		close(cmd->ffd[1]);
	if (cmd->ffd[0] > 0)
		close(cmd->ffd[0]);
}

void	redic_open(t_cmd *cmd)
{
	if (cmd->name != NULL)
		filein(cmd);
	if (cmd->ffd[0] > 0)
		dup2(cmd->ffd[0], STDIN_FILENO);
	if (cmd->ffd[1] > 0)
		dup2(cmd->ffd[1], STDOUT_FILENO);
	close(cmd->ffd[0]);
	close(cmd->ffd[1]);
}

void	exec_pipe(t_data *dt)
{
	t_cmd	*cmd;

	cmd = &dt->cmd;
	if (execve(cmd->pathcmd, cmd->cmdarg, cmd->env) == -1)
		printf("%s: command not found\n", cmd->cmdarg[0]);
	exit(0);
}

int	piped(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe error");
		return (-1);
	}
	return (0);
}

int	forcked(void)
{
	g_v.g_pid = fork();
	if (g_v.g_pid < 0)
	{
		perror("fork");
		return (-1);
	}
	return (g_v.g_pid);
}
