/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:55:47 by ababouel          #+#    #+#             */
/*   Updated: 2022/06/23 00:31:29 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (result != NULL)
	{
		ft_memcpy(result, s1, len1);
		ft_memcpy(result + len1, s2, len2 + 1);
	}
	return (result);
}

char	*ft_strjoinbis(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = 0;
	if (!s2)
		return (0);
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (result != NULL)
	{
		ft_memcpy(result, s1, len1);
		ft_memcpy(result + len1, s2, len2 + 1);
	}
	return (result);
}


static void	**ft_dmemcpy(void **dst, const void **src, size_t n)
{
	size_t				index;

	index = 0;
	if (dst == NULL && src == NULL )
		return (NULL);
	while (index < n)
	{
		((unsigned char **)dst)[index] = ((unsigned char **)src)[index];
		index++;
	}
	return (dst);
}

void	**ft_drealloc(void **ptr, size_t size)
{
	char	**dt;

	dt = malloc(size);
	ft_dmemcpy((void **)dt,(const void **) ptr, size);
	ft_freememory((char **)ptr, ft_dstrlen((char **)ptr));
	return ((void **)dt);
}