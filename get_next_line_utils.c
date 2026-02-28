/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:31:18 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/02/28 15:18:59 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	dst = malloc(ft_strlen_gnl(s) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	d = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!d)
		return (NULL);
	while (s1[i])
		d[j++] = s1[i++];
	i = 0;
	while (s2[i])
		d[j++] = s2[i++];
	d[j] = '\0';
	return (d);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
	{
		if (n > 0 && dst)
			dst[0] = '\0';
		return (0);
	}
	if (n == 0)
		return (ft_strlen_gnl(src));
	while (src[i] && i < n - 1 && src[i] != '\0')
	{
		if (dst)
			dst[i] = src[i];
		i++;
	}
	if (dst)
		dst[i] = '\0';
	return (ft_strlen_gnl(src));
}
