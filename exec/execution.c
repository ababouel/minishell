/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:11:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/04 19:16:09 by ababouel         ###   ########.fr       */
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
            printf("%s: command not found\n", cmd->cmdarg[0]);
    }
    if (pid > 0)
        waitpid(-1, NULL, 0);
}

void exec_redic(t_cmd *cmd)
{
    int pid;

    pid = forcked();
    if (pid == 0)
    {
        if (cmd->name != NULL)
            filein(cmd);
        if(cmd->ffd[0] > 0)
        {
            dup2(cmd->ffd[0], STDIN_FILENO);
            close(cmd->ffd[0]);
        }
        if (cmd->ffd[1] > 0)
        {
            dup2(cmd->ffd[1], STDOUT_FILENO);
            close(cmd->ffd[1]);
        }
        exec_cmd(cmd);
        exit(0);
    }
    waitpid(-1, NULL, 0);
}
