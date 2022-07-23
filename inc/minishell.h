/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:27:31 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/23 17:55:03 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "exec.h"

void		execution(t_lsdata *data);
char		*readline_t(void);
t_lsnode	*add_init_lstok(t_lsnode *lstok, char *line);
int			delete_var(t_lsnode *lstok, t_env *env);
char		**dup_env(char **env);

#endif
