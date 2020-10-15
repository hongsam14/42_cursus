/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/15 23:32:43 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			*gnl_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*c;
	size_t			i;

	i = 0;
	if ((p = (void *)malloc(nmemb * size)) == 0)
		return (0);
	c = p;
	while (i++ < nmemb * size)
		*c++ = 0;
	return (p);
}

static char			*cut_buffer(char **buffer, size_t buf_size)
{
	char			*out;
	char			*buf_start;
	char			*n_point;
	size_t			out_size;

	buf_start = *buffer;
	n_point = gnl_strchr(*buffer, '\n');
	if (n_point == 0)
		return (0);
	out_size = n_point - buf_start;
	out = gnl_substr(buf_start, 0, out_size);
	*buffer = gnl_substr(n_point + 1, 0, buf_size - out_size);
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

	output = 0;
	while (output == 0)
	{
		if ((gnl_strchr(buffer, '\n')) == 0)
		{
			if ((tmp = (char *)gnl_calloc(sizeof(char), BUFFER_SIZE + 1)) == 0)
			{
				if (buffer != 0)
					free(buffer);
				return (-1);
			}
			if ((read(fd, tmp, BUFFER_SIZE)) == 0)
			{
				*line = buffer;
				free(tmp);
				return (0);
			}
			buffer = join_buffer(buffer, tmp);
		}
		output = cut_buffer(&buffer, gnl_strlen(buffer));
	}
	*line = output;
	return (1);
}
