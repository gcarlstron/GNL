/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpacheco <gpacheco@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:27:43 by gpacheco          #+#    #+#             */
/*   Updated: 2022/01/20 17:28:27 by gpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	s_len;

	r = malloc(sizeof(char) * 1);
	s_len = ft_strlen((char *)s);
	if (len > (s_len - start))
		len = s_len - start;
	if (s_len < start)
	{
		r[0] = '\0';
		return (r);
	}	
	r = malloc(sizeof(char) * len + 1);
	if (!r || !s)
		return (NULL);
	i = 0;
	while (i < len && (s + start)[i])
	{
		r[i] = (s + start)[i];
		i++;
	}
	r[i] = '\0';
	return (r);
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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	if (dsize == 0)
		return (ft_strlen(s));
	while (i < dsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(s));
}
