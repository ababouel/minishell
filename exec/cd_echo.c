/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:12 by sismaili          #+#    #+#             */
/*   Updated: 2022/05/21 16:37:09 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_env_oldpwd(t_env *sh)
{
	char	str[100];
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	getcwd(str, sizeof(str));
	while (sh->envi[i])
	{
		if (!ft_strncmp(sh->envi[i], "OLDPWD", ft_strlen("OLDPWD")))
		{
			while (sh->envi[i][j] != '=')
				j++;
			while (str[len])
				sh->envi[i][++j] = str[len++];
			sh->envi[i][++j] = '\0';
			break ;
		}
		i++;
	}
}

void	ft_env_pwd(t_env *sh)
{
	char	str[100];
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	getcwd(str, sizeof(str));
	while (sh->envi[i])
	{
		if (!ft_strncmp(sh->envi[i], "PWD", ft_strlen("PWD")))
		{
			while (sh->envi[i][j] != '=')
				j++;
			while (str[len])
				sh->envi[i][++j] = str[len++];
			sh->envi[i][++j] = '\0';
			break ;
		}
		i++;
	}
}

void	ft_cd(char **line, t_env *sh)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	ft_env_oldpwd(sh);
	if (chdir(line[2]) != -1)
		ft_env_pwd(sh);
	i = 0;
	while (sh->envi[i])
		printf("%s\n", sh->envi[i++]);
}

void	ft_echo(char **line)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (line[j])
		j++;
	if (!ft_strncmp(line[2], "-n", ft_strlen(line[2])))
		i++;
	while (line[i])
	{
		printf("%s", line[i++]);
		if (i != j)
			printf(" ");
	}
	if (ft_strncmp(line[2], "-n", ft_strlen(line[2])))
		printf("\n");
}
