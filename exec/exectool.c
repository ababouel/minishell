/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:32:14 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/11 01:13:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void open_here_doc(char *eof,int *fd, int flag)
{
  char  line;
  int   pid;
  if (*fd > 0)
        close(*fd);
  *fd = open("/tmp/hedoc", flag, 0644);
  pid = forcked();
  if (pid == 0)
  {
    dup2(fd, STDOUT_FILENO);
    while(1337)
    {
      line = readline("> "); 
      if (line == eof)
        break; 
    }
  }
}

static void  openfileredic(char *file, int  *fd, int flags)
{
  if (*fd > 0)
        close(*fd);
  *fd = open(file, flags , 0644);
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
      open_here_doc(&cmd->ffd[0], O_RDONLY | O_WRONLY | O_CREAT); 
    if (file[x].type == TOKEN_RINPUT)
      openfileredic(file[x].file,&cmd->ffd[0], O_RDONLY); 
    if (file[x].type == TOKEN_ROUTPUT)
      openfileredic(file[x].file,&cmd->ffd[1], O_WRONLY | O_CREAT | O_TRUNC); 
    if (file[x].type == TOKEN_DROUTPUT)
      openfileredic(file[x].file,&cmd->ffd[1], O_WRONLY | O_CREAT | O_APPEND); 
    x++;
  }
  return (0);
}



void  ft_stat_pipe_dup(t_data *dt, t_lsdata *lsdata)
{
  t_pipe *cupipe;
  t_pipe *pvpipe;
  t_data *data;
  
  data = lsdata->head;
  cupipe = &dt->pipe;
  if (dt->prev != NULL)
    pvpipe = &dt->prev->pipe;
  if (cupipe->statpipe == START)
    dup2(cupipe->pfd[1], STDOUT_FILENO); 
  if (cupipe->statpipe == UPDATE)
  {
    dup2(pvpipe->pfd[0], STDIN_FILENO);
    dup2(cupipe->pfd[1], STDOUT_FILENO);
  }
  if (cupipe->statpipe == END)
    dup2(pvpipe->pfd[0], STDIN_FILENO);
  ft_stat_pipe_close(data); 
}

void  ft_stat_pipe_close(t_data *dt)
{
  while (dt)
  {
    if (dt->pipe.pfd[0] > 0)
      close(dt->pipe.pfd[0]);
    if (dt->pipe.pfd[1] > 0)
      close(dt->pipe.pfd[1]);
    if (dt != NULL)
      dt = dt->next;
  } 
}