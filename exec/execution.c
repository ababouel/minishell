/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:11:09 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/16 04:38:18 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"
#include <sys/wait.h>

void    exec_cmd(t_cmd *cmd)
{
    int id;
    id = fork();
    if (id == -1)
        perror("error id");
    if ( id == 0)
    {
        if (execve(cmd->pathcmd, cmd->cmdarg, cmd->env) == -1)
            perror("Error execve");
    }
    if (id > 0)
        waitpid(id, NULL, WNOHANG);
}