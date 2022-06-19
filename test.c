/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/19 23:54:57 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int cmdfunc(int *fdpipe, int num,int std,int pid, char **str, char **env)
{
    pid = fork();
    if (pid < 0)
        return 1;
    if (pid == 0)
    {
        dup2(fdpipe[num], std);
        close(fdpipe[0]);
        close(fdpipe[1]);
        execve(str[0],&str[1],env);
    }
    return (pid);
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

// int main(int ac, char **av, char **env)
// {
//     char *ls[] = {"ls", NULL};
//     char *grep[] = {"grep", "main", NULL};
//     char *wc[] = {"wc", NULL};
//     char **cmd[] = {ls, grep, wc, NULL};
    
//     loop_pipe(cmd);
//     // int  fd1[2];
//     // int  fd2[2];
//     // int  pid1;
//     // int  pid2;
//     // int  pid3;
//     // char *str1[100] = {"/bin/cat","cat","data"}; 
//     // // char *str3[100] = {"/usr/bin/uniq","uniq"};
//     // char *str2[100] = {"/usr/bin/sort","sort"};
    
//     // if (pipe(fd1) == -1)
//     //    return (1);
//     // // if (pipe(fd2) == -1)
//     // //    return (2);
//     // pid1 = cmdfunc(fd1, 1, STDOUT_FILENO, pid1, str1, env);
//     // pid2 = cmdfunc(fd1, 0, STDIN_FILENO, pid2, str2, env);
//     // // pid3 = cmdfunc(fd2, 0, STDIN_FILENO, pid3, str3, env);
//     // close(fd1[0]);
//     // close(fd1[1]);
//     // // close(fd2[1]);
//     // // close(fd2[0]);
//     // waitpid(pid1, NULL, 0);
//     // waitpid(pid2, NULL, 0);
//     // // waitpid(pid3, NULL, 0);
//     // printf("Im here\n");
//     return (0); 
// }