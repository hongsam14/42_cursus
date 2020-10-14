/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/14 19:54:45 by suhong           ###   ########.fr       */
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

static char			*join_buffer(char *origin, char *add)
{
	char		*o_tmp;
	char		*tmp;

	tmp = 0;
	if (origin == 0)
		return (add);
	o_tmp = origin;
	tmp = gnl_strjoin(o_tmp, add);
	free(o_tmp);
	free(add);
	return (tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	static ssize_t	size = BUFFER_SIZE;
	static int		index = 0;
	char			*tmp;
	char			*output;

	output = 0;
	while (output == 0 && size == BUFFER_SIZE)
	{
		if ((tmp = (char *)gnl_calloc(sizeof(char), BUFFER_SIZE + 1)) == 0)
		{
			free(buffer);
			return (-1);
		}
		size = read(fd, tmp, BUFFER_SIZE);
		buffer = join_buffer(buffer, tmp);
	}
	output = cut_buffer(&buffer, gnl_strlen(buffer));
	line[index++] = output;
	if (size < BUFFER_SIZE && *buffer == 0)
	{
		free(buffer);
		return (0);
	}
	return (1);
}
