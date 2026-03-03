/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:17:16 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/03/03 23:29:01 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return ();
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
