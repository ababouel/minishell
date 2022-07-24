/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:41:51 by sismaili          #+#    #+#             */
/*   Updated: 2022/07/24 17:08:48 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static char	*remove_fplus(char *value, char c)
{
	int	i;

	i = -1;
	while (value[++i])
	{
		if (value[i] == c)
		{
			while (value[i])
			{
				value[i] = value[i + 1];
				i++;
			}
			i = -1;
			return (value);
		}
	}
	return (value);
}
static int ft_strl(char *val, char c)
{
	size_t	len;

	len = 0;
	while (val[len] != '\0' && val[len] != c)
        len++;
	return (len); 
}
static t_val	*search_plus(t_val *env, char *val)
{
    int sizeval;
    int sizeenv;
    int number;

    sizeval = ft_strl(val, '+');
    number = 0;
    while(env && env->value != NULL)
    {
        sizeenv = ft_strl(env->value, '=');
	// printf("val = %d\n", sizeval);
	// 	printf("env = %d\n", sizeenv);
	// 	printf("value = %s\n", env->value);
	// 	printf("value2 = %s\n", val);
        number = ft_strncmp(env->value, val, sizeval);
		// printf("num = %d\n", number);
        if (number == 0 && sizeenv == sizeval)
            break;     
        env = env->next;
    }
    return (env);
}
static t_val	*equal_export(t_cmd *cmd, int i, t_val *env)
{
	char	*temp;
	t_val	*result;

	temp = NULL;
	result = NULL;
	result = search_val(env, cmd->cmdarg[i]);
	if (result)
	{
		temp = result->value;
		result->value = ft_strdup(cmd->cmdarg[i]);
		free(temp);
		temp = NULL;
		return (NULL);
	}
	result = add_val(cmd->cmdarg[i]);
	return (result);
}
static t_val	*plus_export(char *cmd, t_val *env)
{
	char	*temp;
	char	*temp2;
	t_val	*result;

	temp = NULL;
	temp2 = NULL;
	result = search_plus(env, cmd);
	if (result)
	{
		temp = strchr(cmd, '=');
		temp2 = strchr(result->value, '=');
		if (temp2 == NULL)
			result->value = ft_strjoinbis(result->value, &temp[0]);
		else
			result->value = ft_strjoinbis(result->value, &temp[1]);
		return (NULL);
	}
	result = add_val(remove_fplus(cmd, '+'));
	return (result);
}

static void	check_export(t_cmd *cmd, int i)
{
	int		j;
	int		check;
	t_val	*result;
	char	*temp;

	j = 0;
	check = 0;
	result = NULL;
	temp = NULL;
	while (cmd->cmdarg[i][j])
	{
		if ((cmd->cmdarg[i][j] == '=' || (cmd->cmdarg[i][j] == '+'
			&& cmd->cmdarg[i][j + 1] == '=')) && check == 0)
		{	
			if (cmd->cmdarg[i][j] == '+')
			{
				temp = ft_strdup(cmd->cmdarg[i]);
				result = plus_export(cmd->cmdarg[i], cmd->env->head);
				if (result)
					add_node(cmd->env, result);
				result = NULL;
				result = plus_export(temp, cmd->export->head);
				if (result)
					add_node(cmd->export, result);
				free (temp);
				temp = NULL;
				return ;
			}
			else
			{
				result = equal_export(cmd, i, cmd->env->head);
				if (result)
					add_node(cmd->env, result);
				result = equal_export(cmd, i, cmd->export->head);
				if (result)
					add_node(cmd->export, result);
				return ;
			}
		}
		if (!ft_isalpha(cmd->cmdarg[i][j]) && cmd->cmdarg[i][j] != '_'
			&& !ft_isdigit(cmd->cmdarg[i][j]))
			check = 1;
		j++;
	}
	result = exportenv(cmd, i, j, check);
	if (result)
		add_node(cmd->export, result);
}

int	ft_export(t_cmd *cmd)
{
	int	i;
	t_val *head;

	i = 1;
	head = NULL;
	if (!cmd->cmdarg[i])
	{
		sorting(cmd->export->head);
		head = cmd->export->head;
		while (head)
		{
			printf("declare -x %s\n", head->value);
			head = head->next;
		}
		return (0);
	}
	while (cmd->cmdarg[i])
	{
		if (ft_isalpha(cmd->cmdarg[i][0]) || cmd->cmdarg[i][0] == '_')
		{
			if (!(cmd->cmdarg[i][0] == '_' && cmd->cmdarg[i][1] == '='))
				check_export(cmd, i);
		}
		else
			return (printf("export: `%s': not a valid identifier\n",
					cmd->cmdarg[i]), 1);
		i++;
	}
	return (0);
}
