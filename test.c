/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/25 07:55:40 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

# define null   0
# define start  1
# define middle 2
# define end    3
typedef enum	e_type
{	
	TK_HEREDOC =  10,	
	TK_RINPUT =  11,	
	TK_DROUTPUT =  12,	
	TK_ROUTPUT =  13	
}	t_type;
typedef struct file
{
  char    *file;
  t_type  type;
} t_file;

typedef struct filed
{
  int    ffin;
  int    ffout;
  t_type type;
} t_ffd;

typedef struct data
{
  int     pfd[2];
  t_ffd   ffd;
  t_file  *file;
  char    *delim;
  char    **env;
} t_data;



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

int *filename(t_data *dt)
{
  int     x;
  int     *fd;
  t_file  *file;

  x = 0;
  fd = malloc(sizeof(int) * 2);
  file = dt->file;
  while (file[x].file != NULL)
  {
    if (file[x].type == TK_HEREDOC)
    {
      fd[0] = open("/tmp/hedoc", O_RDONLY | O_WRONLY | O_CREAT , 0777);
      dup2(fd[0], STDOUT_FILENO);
      close(fd[0]);
    }
    if (file[x].type == TK_RINPUT)
    {
      fd[0] = open(file[x].file, O_RDONLY , 0777);      
      dup2(fd[0], STDOUT_FILENO);
      close(fd[0]);
    }
    if (file[x].type == TK_ROUTPUT)
    {
      fd[1] = open(file[x].file, O_RDONLY |   O_CREAT | O_TRUNC , 0777);
      dup2(fd[1], STDIN_FILENO);
      close(fd[1]);
    }
    if (file[x].type == TK_DROUTPUT)
    {
      fd[1] = open(file[x].file, O_WRONLY | O_CREAT | O_APPEND, 0777);
      dup2(fd[1], STDIN_FILENO);
      close(fd[1]);
    }
        
    x++;
  }
  return (fd);
}

// void cmdrdout(t_data *dt, char **cmd)
// {
//   dup2(dt->ffd.ffd, STDOUT_FILENO);
//   close(dt->ffd.ffd);
//   if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
//     perror(cmd[1]);
// }

// void cmdrdin(t_data *dt, char **cmd)
// {
//   dup2(dt->ffd.ffd, STDIN_FILENO);
//   close(dt->ffd.ffd);
//   if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
//     perror(cmd[1]);
// }

// void cmddrdin(t_data *dt, char **cmd)
// {
//   dup2(dt->ffd.ffd, STDIN_FILENO);
//   close(dt->ffd.ffd);
//   if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
//     perror(cmd[1]);
// }

// void cmddrdout(t_data *dt, char **cmd)
// {
//   close(dt->ffd.ffd);
//   if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
//     perror(cmd[1]); 
// }

void redictionfunc(t_data *dt, char **cmd)
{
  int pid1;
  int pid2;
  int pid3;
  int fd;
  
  pid1 = forcked();
  if (pid1 == 0)
  {
    fd = open(dt->file[0].file, O_RDONLY, 0777);
    dup2(fd, STDIN_FILENO);
    pid1 = forcked();
    if (pid1 == 0)
    {
      fd = open(dt->file[0].file, O_RDONLY, 0777);
      dup2(fd, STDIN_FILENO);
      fd = open(dt->file[1].file, O_CREAT | O_TRUNC| O_WRONLY, 0777);
      dup2(fd, STDOUT_FILENO);
      close(fd);
      if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
        perror(cmd[1]);
    }
    pid2 = forcked();
    if (pid2 == 0)
    {
      fd = open(dt->file[0].file, O_RDONLY, 0777);
      dup2(fd, STDIN_FILENO);
      fd = open(dt->file[2].file, O_CREAT | O_TRUNC| O_WRONLY, 0777);
      dup2(fd, STDOUT_FILENO);
      close(fd);
      if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
        perror(cmd[1]);
    }
    pid3 = forcked();
    if (pid3 == 0)
    {
      fd = open(dt->file[3].file, O_CREAT | O_TRUNC| O_WRONLY, 0777);
      dup2(fd, STDOUT_FILENO);
      close(fd);
      if (execve(cmd[0], &(cmd[1]), dt->env) == -1)
        perror(cmd[1]);
    }
  }
  // pid2 = forcked();
  // if(pid2 == 0)
  // {
    
  //   close(fd);
  //   if (execve(cmd[0], &(cmd[1]), dt->env) == -1){}
  //     perror(cmd[1]);
  // :w
  // }
  // // printf("hiiiiii\n"); 
  waitpid(-1, NULL, 0);
}


int cmdfunc(int isin,int fd,char **filein,int isredirect,int track,int *cpipe,int *pvpipe, char **str, char **env)
{
  int pid;

  pid = forcked(); 
  if (pid == 0)
  {
    if (fd > 0 && isin == 1)
      dup2(fd, STDIN_FILENO);
    else if (fd>0 && isin == 0)
      dup2(fd, STDOUT_FILENO);
    if (track == start && fd > 0 && isin != 0)
      dup2(cpipe[1], STDOUT_FILENO);
    if (track == middle)
    {
      dup2(pvpipe[0], STDIN_FILENO);
      dup2(cpipe[1], STDOUT_FILENO);
    }
    if (track == end)
      dup2(cpipe[0], STDIN_FILENO);
    execve(str[0],&str[1],env);
  }
  if (pid > 0)
  { 
    if (track == start)
      close(cpipe[1]);
    if (track == middle)
    {
      close(pvpipe[0]);
      close(cpipe[1]);
    }
    if (track == end)
      close(cpipe[0]);
    if (fd > 0)
      close(fd);
    waitpid(-1, NULL, 0);
  }
  return (pid);
}

t_file  *injectfile(int x,t_file *fl,char *file, t_type type)
{
  fl[x].file = strdup(file);
  fl[x].type = type;
  return (fl);
}

int main(int ac, char **av, char **env)
{ 
    int fd;
    int  fd1[2];
    t_file *file;
    t_data data;
    char *cmd2[100] = {"/usr/bin/wc", "wc", "-c"};
    char *cmd1[100] = {"/bin/cat", "cat"};
    char *strout[100] = {"file2.txt", "file3.txt", "file1.txt"}; 
    char *strin[100] = {"file.txt"};

    file = malloc(sizeof(t_file) * 4);
    file = injectfile(3, file, strout[0], TK_ROUTPUT);
    file = injectfile(1, file, strout[1], TK_ROUTPUT);
    file = injectfile(2, file, strout[2], TK_ROUTPUT);
    file = injectfile(0, file, strin[0], TK_RINPUT);
    
    
    data.file = file;
    data.env = env;
    data.delim = "data";
    pipe(data.pfd);
    redictionfunc(&data, cmd1); 
    return (0); 
}