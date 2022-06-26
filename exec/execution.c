/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:11:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 04:59:29 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

void    exec_cmd(t_cmd *cmd)
{
    int pid;
    
    pid = forcked(); 
    if (pid == 0)
    {
        if (execve(cmd->pathcmd, cmd->cmdarg, cmd->env) == -1)
            perror(cmd->cmdarg[0]);
    }
    if (id > 0)
        waitpid(-1, NULL, 0);
}

void exec_redic(t_redicio *redic,t_cmd *cmd)
{
    int pid;

    pid = forcked();
    if (pid == 0)
    {
        filein(redic);
        if(fd[0] > 0)
        {
            dup2(redic->fd[0], STDIN_FILENO);
            close(redic->fd[0]);
        }
        if (fd[1] > 0)
        {
            dup2(redic->fd[1], STDOUT_FILENO);
            close(redic->fd[1]);
        }
        if (execve(cmd->pathcmd, cmd->cmdarg, dt->env) == -1)
            perror(cmd[0]);
    }
    waitpid(-1, NULL, 0);
}
