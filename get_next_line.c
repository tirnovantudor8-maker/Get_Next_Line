/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tudortirnovan <tudortirnovan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:17:16 by tudortirnov       #+#    #+#             */
/*   Updated: 2026/02/16 19:46:47 by tudortirnov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*depozit;
	char		*felie;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	return (NULL);
}