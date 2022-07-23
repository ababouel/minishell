/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:24:39 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/23 14:40:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

// static void init_env(t_env *env)
// {
//     env->head = NULL;
//     env->tail = NULL;
//     env->size = 0;
// }

// t_val   *add_val(char *env)
// {
//     t_val   *val;

//     val = malloc(sizeof(t_val));
//     val->value = ft_strdup(env);
//     val->next = NULL;
//     return (val);
// }

// t_val   *rm_val(t_val *val)
// {
//     free(val->value);
//     val->value = NULL;
//     free(val);
//     val = NULL;
//     return (val);
// }

// t_val   *search_val(t_val *env, char *val)
// {
//     while(env && env->value != NULL)
//     {
//         if (ft_strncmp(env->value, val, ft_strlens(val)) == 0)
//             return (env);     
//         env = env->next;
//     }
//     return (NULL);
// }

// void    rm_var(t_val *val,char *var)
// {
//     t_val *result;
//     t_val *tprv;
//     t_val *tnxt;
    
//     tprv = NULL;
//     tnxt = NULL;
//     result = search_val(val, var);
//     if (result)
//     {
//         tprv = result->prev;
//         tnxt = result->next;
//         tprv->next = tnxt;
//         tnxt->prev = tprv;
//         result = rm_val(result);
//     }
// }

// void    swap_env(t_val *val1, t_val *val2)
// {
//     char *temp;

//     temp = NULL;
//     temp = val1->value;
//     val1->value = val2->value;
//     val2->value = temp;
// }

// void  exp_sort(t_val *val)
// {
// 	int     j;
//     t_val   *env;

// 	j = 0;
//     env = val;
// 	while (env->next && env->value[j])
// 	{
// 		if (env->value[j] > env->next->value[j])
// 		{
//             swap_env(env, env->next);	
// 			break ;
// 		}
// 		else if (env->value[j] == env->next->value[j])
// 			j++;
// 		else
// 			break ;
// 	}
// }

// void    sorting(t_val *val)
// {
//     t_val *temp;
//     t_val *tmp2;

//     temp = val;
//     while (temp)
//     {
//         tmp2 = val;
//         while (tmp2)
//         {
//             exp_sort(tmp2);
//             tmp2 = tmp2->next;
//         }
//         temp = temp->next;
//     }
// }

// void    add_node(t_env *env, t_val *val)
// {
//     if (env->head == NULL)
//     {
//         env->head = val;
//         env->tail = val;
//     }
//     else
//     {
//         env->tail->next = val;
//         val->prev = env->tail;
//         env->tail = env->tail->next;
//     }
//     env->size += 1;
// }

// void    dup_envis(t_env *lenv, char **env)
// {
//     int x;

//     x = 0;
//     init_env(lenv);
//     while (env[x])
//         add_node(lenv, add_val(env[x++]));
// }