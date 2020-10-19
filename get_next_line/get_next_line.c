/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/20 00:42:28 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ssize_t			read_size;

	if (fd > FOPEN_MAX)
		return (-1);
	output = 0;
	while (output == 0)
	{
		if ((output = gnl_strchr(buffer, '\n')) == 0)
		{
			if ((tmp = (char *)malloc(BUFFER_SIZE + 1)) == 0)
			{
				if (buffer != 0)
				{
					free(buffer);
					buffer = 0;
				}
				return (-1);
			}
			if ((read_size = read(fd, tmp, BUFFER_SIZE)) == 0)
			{
				if (buffer == 0)
				{
					free(tmp);
					*line = gnl_strdup("");
					return (0);
				}
				output = gnl_strdup(buffer);
				*line = output;
				free(buffer);
				free(tmp);
				buffer = 0;
				return (0);
			}
			tmp[read_size] = '\0';
			buffer = join_buffer(buffer, tmp);
		}
		output = cut_buffer(&buffer, output);
	}
	*line = output;
	return (1);
}
