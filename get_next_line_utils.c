/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:45:37 by mmoramov          #+#    #+#             */
/*   Updated: 2022/11/26 13:51:37 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t) ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = -1;
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	ft_free(&s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && (*s != (char) c))
		s++;
	if (*s == (char) c || (char)c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*p;

	len_s = ft_strlen(s);
	i = 0;
	if (len_s <= start)
		len = 0;
	else if (len_s < start + len)
		len = len_s - start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[i] && len--)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
