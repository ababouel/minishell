/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:17:17 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/23 14:40:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_val   *search_val(t_val *env, char *val)
{
    while(env && env->value != NULL)
    {
        if (ft_strncmp(env->value, val, ft_strlen(val)) == 0)
            return (env);     
        env = env->next;
    }
    return (NULL);
}