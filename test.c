/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/20 03:29:14 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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
    {
      dup2(cpipe[0], STDIN_FILENO);
    }
    execve(str[0],&str[1],env);
  }
  if (pid > 0)
  {
    if (track == 1)
    {
      close(cpipe[1]);
      // return (cpipe);
    }
    if (track == 2)
    {
      close(pvpipe[0]);
      close(cpipe[1]);
      // return (cpipe);
    }
    if (track == 3)
    {
      close(cpipe[0]);
      // return (cpipe);
    }
    waitpid(-1, NULL, 0);
  }
  return (0);
}

void    loop_pipe(char ***cmd) 
{
  int   p[2];
  pid_t pid;
  int   fd_in = 0;

  while (*cmd != NULL)
  {
      pipe(p);
      if ((pid = fork()) == -1)
        exit(EXIT_FAILURE);
      else if (pid == 0)
      {
        dup2(fd_in, STDIN_FILENO); //change the input according to the old one 
        if (*(cmd + 1) != NULL)
          dup2(p[1], STDOUT_FILENO);
        close(p[0]);
        close(p[1]);
        execvp((*cmd)[0], *cmd);
        exit(EXIT_FAILURE);
      }
      else
      {
        wait(NULL);
        close(p[1]);
        fd_in = p[0]; //save the input for the next command
        cmd++;
      }
    }
}

int main(int ac, char **av, char **env)
{
//     char *ls[] = {"ls", NULL};
//     char *grep[] = {"grep", "main", NULL};
//     char *wc[] = {"wc", NULL};
//     char **cmd[] = {ls, grep, wc, NULL};
    
    // loop_pipe(cmd);
    int  fd1[2];
    int  fd2[2];
    int  fd3[2];
    char *str1[100] = {"/bin/cat","cat","data"}; 
    char *str3[100] = {"/usr/bin/uniq","uniq"};
    char *str2[100] = {"/usr/bin/sort","sort"};
    char *str4[100] = {"/usr/bin/wc","wc"};
    
    if (pipe(fd1) == -1)
      return (1);
    if (pipe(fd2) == -1)
      return (2);
    if (pipe(fd3) == -1)
      return (3);
    cmdfunc(start, fd1, NULL, str1, env);
    cmdfunc(middle, fd2, fd1, str2, env);
    cmdfunc(middle, fd3, fd2, str3, env);
    cmdfunc(end, fd3, NULL, str4, env);
    return (0); 
}