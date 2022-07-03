/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:32:14 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/03 11:59:31 by ababouel         ###   ########.fr       */
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

int filein(t_cmd *cmd)
{
  int     x;
  t_file  *file;

  x = 0;
  file = cmd->name;
  while (file[x].file != NULL)
  {
    if (file[x].type == TOKEN_DRINPUT)
      cmd->ffd[0] = open("/tmp/hedoc", O_RDONLY | O_WRONLY | O_CREAT , 0777);
    if (file[x].type == TOKEN_RINPUT)
      cmd->ffd[0] = open(file[x].file, O_RDONLY , 0777);
    if (file[x].type == TOKEN_ROUTPUT)
      cmd->ffd[1] = open(file[x].file, O_WRONLY |   O_CREAT | O_TRUNC , 0777);
    if (file[x].type == TOKEN_DROUTPUT)
      cmd->ffd[1] = open(file[x].file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    x++;
  }
  return (0);
}

int piped(int *fd)
{
  if (pipe(fd) == -1)
  {
    perror("pipe error");
    return (-1);
  }
  return (0);
}