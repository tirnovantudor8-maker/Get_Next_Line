/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:31:18 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/03/04 20:41:36 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//finding \n
// if (*s == c) -> finding \n, if it is \n we return char *s/ know where to 
// cut the line if (c == '\0') -> finding \0
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

//tells how much memory to allocate for the strings
size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

//creates a copy of the string into a new memory allocated
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

//glues to strings into one
char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

// first check if src doesnot exists(if n>0 and dst exists then we make dst \0)
//copy the text(or line) from a place to another
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL)
	{
		if (n > 0 && dst)
			dst[0] = '\0';
		return (0);
	}
	if (n == 0)
		return (ft_strlen_gnl(src));
	while (src[i] != '\0' && i < n - 1)
	{
		if (dst)
			dst[i] = src[i];
		i++;
	}
	if (dst)
		dst[i] = '\0';
	return (ft_strlen_gnl(src));
}
