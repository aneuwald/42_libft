/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:16:02 by egomes            #+#    #+#             */
/*   Updated: 2022/02/17 23:57:56 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	null_buffer(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (i < BUFF_GNL)
		buffer[i++] = '\0';
	return (0);
}

int	get_next_line(char **line, int fd)
{
	int		i;
	int		r;
	char	*buffer;
	char	c;

	buffer = (char *)malloc(BUFF_GNL);
	null_buffer(buffer);
	i = 0;
	c = '0';
	r = 1;
	while (r != 0 && c != '\n' && c != '\0')
	{
		r = read(fd, &c, 1);
		if (c == '\n' && c == '\0' && r == 0)
			break ;
		if (c != '\n' && c != '\0' && r != 0)
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}
