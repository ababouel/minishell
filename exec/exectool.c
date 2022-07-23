/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:32:14 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/22 18:59:05by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*search_var1(char *cmd, t_val *env)
{
	int		i;
	char	*new;
	char	*temp;

	i = 0;
	new = NULL;
	temp = NULL;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			new = fill_new(new, cmd, env, &i);	
		else
		{
			temp = malloc(2);
			temp[0] = cmd[i++];
			temp[1] = '\0';
			new = ft_strjoinbis(new, temp);
			free (temp);
		}
	}
		return (new);
}

static void	open_here_doc(char *eof, t_cmd *cmd, int flag)
{
	char	*buf;
	char	fdh;
	int		i;

	i = 0;
	if (cmd->ffd[0] > 0)
		close(cmd->ffd[0]);
	fdh = open("/tmp/.hedoc", flag, 0777);
	while (1337)
	{
		buf = readline("> ");
		i = 0;
		if (buf == NULL || (buf && ft_strcmp(buf, eof) == 0))
			break ;
		buf = search_var1(buf, cmd->env->head);
		write(fdh, buf, ft_strlen(buf));
		write(fdh, "\n", 1);
		free(buf);
	}
	free(buf);
	buf = NULL;
	close(fdh);
	cmd->ffd[0] = open("/tmp/.hedoc", O_RDONLY, 0644);
}

static void	openfileredic(char *file, int *fd, int flags)
{
	if (*fd > 0)
		close(*fd);
	*fd = open(file, flags, 0644);
}

int	filein(t_cmd *cmd)
{
	int		x;
	t_file	*file;

	x = 0;
	file = cmd->name;
	while (file[x].file != NULL)
	{
		if (file[x].type == TOKEN_DRINPUT)
			open_here_doc(file[x].file, cmd,
				O_CREAT | O_RDWR | O_TRUNC);
		if (file[x].type == TOKEN_RINPUT)
		{
			openfileredic(file[x].file, &cmd->ffd[0], O_RDONLY);
			if(cmd->ffd[0] == -1)
			{
				printf("%s: No such file or directory\n", file[x].file);
				g_l.state = 1;
				exit(g_l.state);
			}
		}
		if (file[x].type == TOKEN_ROUTPUT)
			openfileredic(file[x].file, &cmd->ffd[1],
				O_WRONLY | O_CREAT | O_TRUNC);
		if (file[x].type == TOKEN_DROUTPUT)
			openfileredic(file[x].file, &cmd->ffd[1],
				O_WRONLY | O_CREAT | O_APPEND);
		x++;
	}
	return (0);
}

void	ft_stat_pipe_dup(t_data *dt, t_lsdata *lsdata)
{
	t_pipe	*cupipe;
	t_pipe	*pvpipe;
	t_data	*data;

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

void	ft_stat_pipe_close(t_data *dt)
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
