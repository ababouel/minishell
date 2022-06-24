/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/24 06:45:53 by ababouel         ###   ########.fr       */
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


int cmdredirectio(int *fd1,char **filein, char **fileout, char **str, char **env,int flagi, int flago)
{
  int pid;
  int fileo;
  int filei;
  int x;

  x = 0;
  filei = -1;
  fileo = -1;
  // while (fileout[x])
  // {
  //   fileo = open(fileout[x], flago, 0777);
  //   if (fileo == -1)
  //     return (2);
  //   x++;
  // }
  x = 0;
  while (filein[x])
  {
    filei = open(filein[x], flagi, 0777);
    if (filei == -1)
      return (2);
    x++;
  }
  pid = forcked();
  if (pid == 0)
  {
    // if (filei != -1)
    // {
    dup2(filei, STDIN_FILENO);
    dup2(fd1[1],STDOUT_FILENO);
    close(filei);
    close(fd1[1]);
    // }
    // if (fileo != -1)
    // {
    //   dup2(fileo, STDOUT_FILENO);
    //   close(fileo);
    // }
   if (execve(str[0],&str[1],env) == -1)
    perror(str[1]);
  }
  else
  {
    // if (filei != -1)
    close(filei);
    close(fd1[1]);
    // if (fileo != -1)
    //   close(fileo);
    waitpid(-1, NULL, 0);
  }
  return (0);
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




int main(int ac, char **av, char **env)
{
//     char *ls[] = {"ls", NULL};
//     char *grep[] = {"grep", "main", NULL};
//     char *wc[] = {"wc", NULL};
//     char **cmd[] = {ls, grep, wc, NULL};
    
    // loop_pipe(cmd);
    int fd;
    int  fd1[2];
    // int  fd2[2];
    // int  fd3[2];
    char *str1[100] = {"/bin/ls", "ls"};
    char *str4[100] = {"/usr/bin/wc", "wc", "-c"};
    char *str2[100] = {"file2.txt", "file3.txt", "file1.txt"}; 
    char *str3[100] = {"file.txt"};
    // char *str3[100] = {"/usr/bin/uniq","uniq"};
    // char *str2[100] = {"/usr/bin/sort","sort"};
    // char *str4[100] = {"/usr/bin/wc","wc"};
    
    if (pipe(fd1) == -1)
      return (1);
    // cmdredirectio(fd1,str3, NULL, str1, env, O_RDONLY , 0);
    fd = open(str3[0],O_WRONLY|O_CREAT|O_APPEND,0777);
    cmdfunc(1,fd ,NULL, 0, start,fd1, NULL, str1, env);
    // cmdfunc(-1,-1 ,NULL, 0, end,fd1, NULL, str4, env);
    // if (pipe(fd3) == -1)
    //   return (3);
    // cmdfunc(start, fd1, NULL, str1, env);
    // cmdfunc(middle, fd2, fd1, str2, env);
    // cmdfunc(middle, fd3, fd2, str3, env);
    // cmdfunc(end, fd3, NULL, str4, env);
    //  cmdfunc() 
    return (0); 
}