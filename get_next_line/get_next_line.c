/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/19 01:12:02 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char			*cut_buffer(char **buffer, char *n_point)
{
	char			*out;
	char			*buf_start;

	if (n_point == 0)
		return (0);
	buf_start = *buffer;
	out = gnl_substr(buf_start, 0, n_point - buf_start);
	*buffer = gnl_strdup(n_point + 1);
	free(buf_start);
	return (out);
}

static char			*join_buffer(char *buffer, char *add)
{
	char		*b_tmp;
	char		*tmp;

	if (buffer == 0)
		return (add);
	b_tmp = buffer;
	tmp = gnl_strjoin(b_tmp, add);
	free(b_tmp);
	free(add);
	return (tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	char			*tmp;
	char			*output;
	char			*n_point;
	ssize_t			read_size;

	output = 0;
	while (output == 0)
	{
		if ((n_point = gnl_strchr(buffer, '\n')) == 0)
		{
			if ((tmp = (char *)malloc(BUFFER_SIZE + 1)) == 0)
			{
				if (buffer != 0)
					free(buffer);
				return (-1);
			}
			if ((read_size = read(fd, tmp, BUFFER_SIZE)) == 0)
			{
				*line = buffer;
				free(tmp);
				return (0);
			}
			tmp[read_size] = '\0';
			buffer = join_buffer(buffer, tmp);
		}
		output = cut_buffer(&buffer, n_point);
	}
	*line = output;
	return (1);
}

int					main(void)
{
	int				fd;
	char			*line;

	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
