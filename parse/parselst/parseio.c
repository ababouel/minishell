/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:40:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/05 09:33:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int parse_redic(t_data *data, t_token *token)
{
    t_cmd   *cmd;

    cmd = &data->cmd;
    if (cmd->name != NULL && token->value != NULL)
    {
        cmd->numfile += 1;
        cmd->name = ft_realloc((void *)cmd->name, sizeof(t_file) * (cmd->numfile + 1));
        cmd->name[cmd->numfile - 1].file = ft_strdup(token->value);
        cmd->name[cmd->numfile - 1].type = token->type;
        cmd->name[cmd->numfile].file = NULL;
    }
    else
    {
        cmd->name = malloc(sizeof(t_file) * 2);
        cmd->name[0].file = ft_strdup(token->value);
        cmd->name[0].type = token->type;
        cmd->name[1].file = NULL;
        cmd->numfile += 1;
    }
    return(0);
}