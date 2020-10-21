/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/21 19:37:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				cut_buffer(char **buffer, char **out)
{
	char		*buf_start;
	char		*n_point;

	n_point = gnl_strchr(*buffer, '\n');
	if (n_point == 0)
	{
		*out = 0;
		return (1);
	}
	buf_start = *buffer;
	*out = gnl_substr(buf_start, 0, n_point - buf_start);
	*buffer = gnl_strdup(n_point + 1);
	free(buf_start);
	if (*out == 0 || *buffer == 0)
	{
		if (*out != 0)
			free(*out);
		if (*buffer != 0)
		{
			free(*buffer);
			*buffer = 0;
		}
		return (-1);
	}
	return (1);
}

int				join_buffer(char **buffer, char *add)
{
	char		*b_tmp;

	if (*buffer == 0)
	{
		*buffer = add;
		return (1);
	}
	b_tmp = *buffer;
	*buffer = gnl_strjoin(b_tmp, add);
	free(b_tmp);
	free(add);
	if (*buffer == 0)
		return (-1);
	return (1);
}

int				free_buffer(char *buffer)
{
	if (buffer != 0)
	{
		free(buffer);
		buffer = 0;
	}
	return (-1);
}

int				meet_eof(char **buffer, char *tmp, char **line, ssize_t r_size)
{
	char		*out;

	if (*buffer == 0)
	{
		free(tmp);
		if ((out = gnl_strdup("")) == 0)
			return (-1);
		*line = out;
		return (0);
	}
	out = gnl_strdup(*buffer);
	free(tmp);
	free(*buffer);
	*buffer = 0;
	if (out == 0 || r_size == -1)
		return (-1);
	*line = out;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buffer = 0;
	char		*tmp;
	char		*output;
	ssize_t		read_size;

	if (line == 0 || fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	output = 0;
	while (output == 0)
	{
		if ((cut_buffer(&buffer, &output)) == -1)
			return (-1);
		if (output == 0)
		{
			if ((tmp = (char *)malloc(BUFFER_SIZE + 1)) == 0)
				return (free_buffer(buffer));
			if ((read_size = read(fd, tmp, BUFFER_SIZE)) <= 0)
				return (meet_eof(&buffer, tmp, line, read_size));
			tmp[read_size] = '\0';
			if ((join_buffer(&buffer, tmp)) == -1)
				return (-1);
		}
	}
	*line = output;
	return (1);
}
