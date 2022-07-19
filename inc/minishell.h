/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:27:31 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/19 13:55:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "exec.h"

void        execution(t_lsdata *data);
char        *readline_t(void);
t_lsnode    *add_init_lstok(t_lsnode *lstok, char *line);

#endif
