/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/12 22:25:18 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_utils.c"
#define BUFFER_SIZE 1

static char			*cut_buffer(char **buffer, size_t buf_size)
{
	char			*out;
	char			*buf_start;
	char			*n_point;
	size_t			out_size;

	buf_start = *buffer;
	n_point = gnl_strchr(*buffer, '\n');
	if (n_point == 0)
	{
		return (*buffer);
	}
	out_size = n_point - buf_start;
	out = gnl_substr(*buffer, 0, out_size);
	*buffer = gnl_substr(n_point + 1, 0, buf_size - out_size);
	free(buf_start);
	return (out);
}

int					count_equal(char *str, int c, size_t size)
{
	int				count;

	count = 0;
	while (size--)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int					get_line(int fd, char **line)
{
	static char		*buffer = 0;
	static ssize_t	size = BUFFER_SIZE;
	static int		index = 0;
	char			*

	if (size == BUFFER_SIZE)
	{
		while (count_equal(buffer, '\n', size) != 0)
		{
			if((buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
				return (-1);
			if ((size = read(fd, buffer, BUFFER_SIZE)) == 0)
				return (0);
		}
	}
	line[i++] = cut_buffer(&buffer, size);
	return (1);
}

int					main(void)
{
	int				fd;

	fd = open("test.txt", O_RDONLY);
	get_line(fd);
	get_line(fd);
	return (0);
}
