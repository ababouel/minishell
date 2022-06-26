/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redicio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:32:14 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/26 03:00:34 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int forcked()
{
  int pid;

  pid = fork();
  if (pid < 0)
  {
    perror("fork");
    return (-1);
  }
  return (pid);
}

int *filein(t_data *dt)
{
  int     x;
  int     *fd;
  t_file  *file;

  x = 0;
  fd = malloc(sizeof(int) * 2);
  file = dt->file;
  while (file[x].file != NULL)
  {
    if (file[x].type == TOKEN_)
      fd[0] = open("/tmp/hedoc", O_RDONLY | O_WRONLY | O_CREAT , 0777);
    if (file[x].type == TK_RINPUT)
      fd[0] = open(file[x].file, O_RDONLY , 0777);
    if (file[x].type == TK_ROUTPUT)
      fd[1] = open(file[x].file, O_WRONLY |   O_CREAT | O_TRUNC , 0777);
    if (file[x].type == TK_DROUTPUT)
      fd[1] = open(file[x].file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    x++;
  }
  return (fd);
}

void redictionfunc(t_cmd *cmd)
{
    int pid1;
    int *fd;

    pid1 = forcked();
    if (pid1 == 0)
    {
        fd = filein(dt);
        dup2(fd[0] ,STDIN_FILENO);
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
            perror(cmd[1]);
    }
    waitpid(-1, NULL, 0);
}
