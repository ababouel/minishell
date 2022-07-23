/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:24:39 by ababouel          #+#    #+#             */
/*   Updated: 2022/07/23 04:45:28 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static size_t	ft_strlens(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	ft_strncmps(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

static char	*ft_strdups(const char *s)
{
	char	*data;
	int		index;

	data = malloc((ft_strlens(s) + 1) * sizeof(char));
	if (!data)
		return (0);
	index = 0;
	while (s[index])
	{
		data[index] = s[index];
		index++;
	}
	data[index] = '\0';
	return (data);
}

// some tools 

static void init_env(t_env *env)
{
    env->head = NULL;
    env->tail = NULL;
    env->size = 0;
}

t_val   *add_val(char *env)
{
    t_val   *val;

    val = malloc(sizeof(t_val));
    val->value = ft_strdups(env);
    val->next = NULL;
    return (val);
}

t_val   *rm_val(t_val *val)
{
    free(val->value);
    val->value = NULL;
    free(val);
    val = NULL;
    return (val);
}

t_val   *search_val(t_val *env, char *val)
{
    while(env && env->value != NULL)
    {
        if (ft_strncmps(env->value, val, ft_strlens(val)) == 0)
            return (env);     
        env = env->next;
    }
    return (NULL);
}

void    rm_var(t_val *val,char *var)
{
    t_val *result;
    t_val *tprv;
    t_val *tnxt;
    
    tprv = NULL;
    tnxt = NULL;
    result = search_val(val, var);
    if (result)
    {
        tprv = result->prev;
        tnxt = result->next;
        tprv->next = tnxt;
        tnxt->prev = tprv;
        result = rm_val(result);
    }
}

void    swap_env(t_val *val1, t_val *val2)
{
    char *temp;

    temp = NULL;
    temp = val1->value;
    val1->value = val2->value;
    val2->value = temp;
}

void  exp_sort(t_val *val)
{
	int     j;
    t_val   *env;

	j = 0;
    env = val;
	while (env->next && env->value[j])
	{
		if (env->value[j] > env->next->value[j])
		{
            swap_env(env, env->next);	
			break ;
		}
		else if (env->value[j] == env->next->value[j])
			j++;
		else
			break ;
	}
}

void    sorting(t_val *val)
{
    t_val *temp;
    t_val *tmp2;

    temp = val;
    while (temp)
    {
        tmp2 = val;
        while (tmp2)
        {
            exp_sort(tmp2);
            tmp2 = tmp2->next;
        }
        temp = temp->next;
    }
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

int main(int ac, char **av, char **env)
{
    t_env lenv;
    t_val *val;
    t_val *lsval;

    dup_envis(&lenv, env);
    // val = lenv.tail;
    // while (val && val->value != NULL)
    // {
    //     printf("%s\n", val->value);
    //     val = val->prev;
    // }
    // val = search_val(lsval, "PATH");
    // if (val != NULL)
    //     printf("%s\n", val->value); 
    add_node(&lenv, add_val("HELLO="));
    val = lenv.head;
    while (val && val->value != NULL)
    {
         printf("%s\n", val->value);
         val = val->next;
    }
    printf("**********************************\n");
    printf("**********************************\n");
    printf("**********************************\n");
    sorting(lenv.head);
    val = lenv.head;
    while (val && val->value != NULL)
    {
         printf("%s\n", val->value);
         val = val->next;
    }
    return (0);
}
