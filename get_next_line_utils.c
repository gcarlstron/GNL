/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpacheco <gpacheco@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:49:26 by gpacheco          #+#    #+#             */
/*   Updated: 2021/10/06 21:55:25 by gpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	if (c >= 256)
		c %= 256;
	p = NULL;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c || c == '\0')
		p = (char *)s + i;
	return (p);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	if (dsize == 0)
		return (ft_strlen(s));
	while (i < dsize - 1 && src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		size1;
	int		size2;

	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	r = malloc(size1 + size2 + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, size1 + 1);
	ft_strlcpy(r + size1, s2, size2 + 1);
	return (r);
}