/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:39:18 by suhong            #+#    #+#             */
/*   Updated: 2020/10/11 21:17:08 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			free_left(char *str)
{
	free(str);
	return (-1);
}

static size_t		equal_count(const char *str, int c, ssize_t size)
{
	size_t			i;

	i = 0;
	while (size--)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

static void			

int					get_next_line(int fd, char **line)
{
	static size_t	count = 0;
	ssize_t			r_size;
	char			*buffer;

	if ((buffer = (char *)malloc(BUFFER_SIZE)) == 0)
		return (free_left(remain));
	if ((r_size = read(fd, buffer, BUFFER_SIZE)) < 0)
	{
		free(buffer);
		return (free_left(remain));
	}
	count += equal_count(buffer, '\n', r_size);
}
