/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpacheco <gpacheco@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:27:43 by gpacheco          #+#    #+#             */
/*   Updated: 2022/01/21 11:53:37 by gpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	s_len;

	r = malloc(sizeof(char) * 1);
	s_len = 0;
	while (s[len] != '\0')
	{
		s_len++;
	}
	if (len > (s_len - start))
		len = s_len - start;
	if (s_len < start)
		return ('\0');
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

	size1 = 0;
	while (s1[size1] != '\0')
	{
		size1++;
	}
	size2 = 0;
	while (s2[size2] != '\0')
	{
		size2++;
	}
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
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
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
		return (0);
	while (i < dsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}
