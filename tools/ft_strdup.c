/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:45:20 by ababouel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/18 01:47:37 by ababouel         ###   ########.fr       */
=======
/*   Updated: 2022/06/17 21:23:33 by ababouel         ###   ########.fr       */
>>>>>>> 959f7b588f1bffda7aeb0b24207b7e2cf04e0450
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strdup(const char *s)
{
	char	*data;
	int		index;

	data = malloc((ft_strlen(s) + 1) * sizeof(char));
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

int	is_alpha(char c)
{
	if (('A' <= c && c <= 'Z') 
		|| ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

int	is_filename(char c)
{
	if(('A' <= c && c <= 'Z')
		|| ('a'<= c && c <= 'z')
		|| ('0'<= c && c <= '9')
		|| c == '_' || c == '.'
		|| c == '/' || c == '=')
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	x;
	unsigned char	*str;

	x = 0;
	str = s;
	while (x < n)
	{
		str[x] = (unsigned char ) 0;
		x++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}