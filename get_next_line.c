/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:17:16 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/03/05 20:58:57 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stitch_together(char *leftover, char *plate)
{
	char	*stitched_str;

	if (!plate)
		return (leftover);
	if (!leftover)
		return (ft_strdup_gnl(plate));
	stitched_str = ft_strjoin_gnl(leftover, plate);
	free(leftover);
	return (stitched_str);
}

static char	*read_until_nl(int fd, char *leftover)
{
	char	*plate;
	ssize_t	bytes_read;

	plate = malloc(BUFFER_SIZE + 1);
	if (!plate)
		return (free(leftover), NULL);
	while (!leftover || !ft_strchr_gnl(leftover, '\n'))
	{
		bytes_read = read(fd, plate, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (plate);
			free (leftover);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		plate[bytes_read] = '\0';
		leftover = stitch_together(leftover, plate);
		if (!leftover)
			return (free(plate), NULL);
	}
	free (plate);
	return (leftover);
}

static char	*get_result(char *stitched)
{
	char	*result;
	char	*nl_position;
	size_t	len;

	if (!stitched || !stitched[0])
		return (NULL);
	nl_position = ft_strchr_gnl(stitched, '\n');
	if (nl_position)
		len = nl_position - stitched + 1;
	else
		len = ft_strlen_gnl(stitched);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy_gnl(result, stitched, len + 1);
	return (result);
}

char	*get_leftover(char *stitched)
{
	char	*nl_position;
	size_t	len;
	char	*new_leftover;

	if (!stitched)
		return (NULL);
	nl_position = ft_strchr_gnl(stitched, '\n');
	if (!nl_position || *(nl_position + 1) == '\0')
		return (NULL);
	len = ft_strlen_gnl(nl_position + 1);
	new_leftover = malloc(len + 1);
	if (!new_leftover)
		return (NULL);
	ft_strlcpy_gnl(new_leftover, nl_position + 1, len + 1);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*result;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_until_nl(fd, leftover);
	if (!leftover || !leftover[0])
		return (free(leftover), leftover = NULL);
	result = get_result(leftover);
	if (!result)
		return (free(leftover), leftover = NULL);
	tmp = leftover;
	leftover = get_leftover(leftover);
	free(tmp);
	return (result);
}
