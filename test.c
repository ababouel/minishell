/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/21 00:37:11 by ababouel         ###   ########.fr       */
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


int cmdredirectio(char **files,char **str, char **env, int flag, int std)
{
  int pid;
  int file;
  int x;

  x = 0;
  while (files[x])
  {
    file = open(files[x], flag, 0777);
    if (file == -1)
      return (2);
    x++;
  } 
  pid = fork();
  if (pid < 0)
    return (1);
  if (pid == 0)
  {
    dup2(file,std);
    close(file);
    execve(str[0],&str[1],env);
  }
  else
  {
    close(file);
    waitpid(-1, NULL, 0);
  }
  return (0);
}

int cmdfunc(char **file,int isredirect,int track,int *cpipe,int *pvpipe, char **str, char **env)
{
  int pid;

  pid = forcked; 
  if (pid == 0)
  {
    if (track == 1)
      dup2(cpipe[1], STDOUT_FILENO);
    if (track == 2)
    {
      dup2(pvpipe[0], STDIN_FILENO);
      dup2(cpipe[1], STDOUT_FILENO);
    }
    if (track == 3)
      dup2(cpipe[0], STDIN_FILENO);
    if (isredirect == 1)
      cmdredirectio(file, str, env, O_WRONLY | O_CREAT |O_TRUNC, STDOUT_FILENO);
    else
      execve(str[0],&str[1],env);
  }
  if (pid > 0)
  {
    if (track == 1)
      close(cpipe[1]);
    if (track == 2)
    {
      close(pvpipe[0]);
      close(cpipe[1]);
    }
    if (track == 3)
      close(cpipe[0]);
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
    // int  fd1[2];
    // int  fd2[2];
    // int  fd3[2];
    char *str1[100] = {"/bin/ls", "ls", "-la"};
    char *str2[100] = {"file2.txt", "file3.txt", "file1.txt"}; 
    char *str3[100] = {"file.txt"};
    // char *str3[100] = {"/usr/bin/uniq","uniq"};
    // char *str2[100] = {"/usr/bin/sort","sort"};
    // char *str4[100] = {"/usr/bin/wc","wc"};
    
    // if (pipe(fd1) == -1)
    //   return (1);
    // if (pipe(fd2) == -1)
    //   return (2);
    // if (pipe(fd3) == -1)
    //   return (3);
    // cmdfunc(start, fd1, NULL, str1, env);
    // cmdfunc(middle, fd2, fd1, str2, env);
    // cmdfunc(middle, fd3, fd2, str3, env);
    // cmdfunc(end, fd3, NULL, str4, env);
    cmdredirectio(str2, str1,) 
    return (0); 
}