/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/15 22:14:59 by suhong           ###   ########.fr       */
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

	n_point = gnl_strchr(*buffer, '\n');
	if (n_point == 0)
		return (0);
	buf_start = *buffer;
	out_size = n_point - buf_start;
	out = gnl_substr(buf_start, 0, out_size);
	*buffer = gnl_substr(n_point + 1, 0, buf_size - out_size);
	free(buf_start);
	return (out);
}

static void			join_buffer(char **buffer, char *add)
{
	char		*b_tmp;

	if (*buffer == 0)
	{
		*buffer = add;
		return ;
	}
	b_tmp = *buffer;
	*buffer = gnl_strjoin(*buffer, add);
	free(add);
	free(b_tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	char			*tmp;
	char			*output;

	output = 0;
	while (*buffer == 0 || output == 0)
	{
		if ((tmp = (char *)gnl_calloc(sizeof(char), BUFFER_SIZE + 1)) == 0)
		{
			if (buffer != 0)
				free(buffer);
			return (-1);
		}
		if ((read(fd, tmp, BUFFER_SIZE)) == 0)
		{
			free(tmp);
			return (0);
		}
		join_buffer(&buffer, tmp);
		output = cut_buffer(&buffer, gnl_strlen(buffer));
	}
	*line = output;
	return (1);
}
