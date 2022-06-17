/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:41:51 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/24 15:26:33 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_export(t_env *sh, char **line, int i, int len)
{
	int	j;

	if (ft_isalpha(line[i][0]))
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == '=')
			{
				sh->envi[len] = line[i];
				sh->envi[++len] = NULL;
				return ;
			}
			j++;
		}
	}
}

void	ft_export(char **line, t_env *sh)
{
	int	i;
	int	len;

	i = 2;
	len = 0;
	while (sh->envi[len])
		len++;
	while (line[i])
	{
		check_export(sh, line, i, len);
		i++;
		len++;
	}
	i = 0;
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}

void	check_unset(t_env *sh, char **line, int i)
{
	int	j;

	j = 0;
	while (sh->envi[j])
	{
		if (!ft_strncmp(line[i], sh->envi[j], ft_strlen(line[i])))
		{
			while (sh->envi[j])
			{
				sh->envi[j] = sh->envi[j + 1];
				j++;
				if (sh->envi[j + 1] == NULL)
				{
					sh->envi[j] = NULL;
					break ;
				}
			}
		}
		else
			j++;
	}
}

void	ft_unset(char **line, t_env *sh)
{
	int	i;

	i = 2;
	while (line[i])
	{
		check_unset(sh, line, i);
		i++;
	}
	i = 0;
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}
