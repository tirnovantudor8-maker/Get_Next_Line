/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:17:16 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/03/04 02:02:34 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stitch_together(char *leftover, char *buffer)
{
	char	*stitched_str;

	if (!buffer)
		return (leftover);
	if (!leftover)
		return (ft_strdup(buffer));
	stitched_str = ft_strjoin_gnl(leftover, buffer);
	free(leftover);
	return (stitched_str);
}


static char	*read_until_nl(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes_read;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(leftover), NULL);
	while (!leftover || !ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
		{
			free (buffer);
			free (leftover);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		leftover = stitch_together(leftover, buffer);
		if (!leftover)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (leftover);	
}





char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*result;
	// char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_until_nl(fd, leftover);
	return (result);
}


// int	main()
// {
// 	char *s;
// 	int	fd = open("balls.txt", O_RDONLY);

// 	while ((s = get_next_line(fd)) != NULL)
// 	{
// 		printf("[%s]", s);
// 		free(s);
// 	}
// 	close(fd);
// 	return 0;
	
// }
