/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/20 18:28:43 by ababouel         ###   ########.fr       */
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

int cmdfunc(int track,int *cpipe,int *pvpipe, char **str, char **env)
{
  int pid;
  pid = fork();
  if (pid < 0)
    return 1;
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
  return (0);
}

int cmdredirectoutput(char **str, char **env, int flag)
{
  int pid;
  int file;
  int x;
  char data[3][1000] ={"file1.txt","file2.txt","file3.txt"}; 

  x = 0;
  while (x < 3)
  {
    file = open(data[x], O_WRONLY | O_CREAT | flag, 0777);
    if (file == -1)
      return (2);
    x++;
  } 
  pid = fork();
  if (pid < 0)
    return (1);
  if (pid == 0)
  {
    dup2(file,STDOUT_FILENO);
    close(file);
    execve(str[0],&str[1],env);
  }
  else
  {
    close(file);
    waitpid(-1, NULL, 0);
  }
  close(file);
  return (0);
}

int cmdredirectinput(char **str, char **env, int flag)
{
  int pid;
  int file;
  int x;
  char data[3][1000] ={"file1.txt","file2.txt","file3.txt"}; 

  x = 0;
  while (x < 3)
  {
    file = open(data[x], flag, 0777);
    if (file == -1)
      return (2);
    x++;
  } 
  pid = fork();
  if (pid < 0)
    return (1);
  if (pid == 0)
  {
    dup2(file,STDIN_FILENO);
    close(file);
    execve(str[0],&str[1],env);
  }
  else
  {
    close(file);
    waitpid(-1, NULL, 0);
  }
  close(file);
  return (0);
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
    char *str1[100] = {"/usr/bin/wc","wc","-lwc"}; 
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
    // cmdredirectoutput(str1,env, O_APPEND);
    cmdredirectinput(str1,env, O_RDONLY);
    return (0); 
}