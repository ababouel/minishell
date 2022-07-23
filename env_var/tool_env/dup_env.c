/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:12:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/23 14:22:17 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void init_env(t_env *env)
{
    env->head = NULL;
    env->tail = NULL;
    env->size = 0;
}

static t_val   *add_val(char *env)
{
    t_val   *val;

    val = malloc(sizeof(t_val));
    val->value = ft_strdup(env);
    val->next = NULL;
    return (val);
}

void    add_node(t_env *env, t_val *val)
{
    if (env->head == NULL)
    {
        env->head = val;
        env->tail = val;
    }
    else
    {
        env->tail->next = val;
        val->prev = env->tail;
        env->tail = env->tail->next;
    }
    env->size += 1;
}

void    dup_envis(t_env *lenv, char **env)
{
    int x;

    x = 0;
    init_env(lenv);
    while (env[x])
        add_node(lenv, add_val(env[x++]));
}