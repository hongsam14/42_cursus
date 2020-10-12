/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:55:30 by suhong            #+#    #+#             */
/*   Updated: 2020/10/12 23:40:54 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_utils.c"
#define BUFFER_SIZE 5

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

void				join_str(char **origin, char *add)
{
	char			*o_tmp;
	char			*a_tmp;

	if (*origin == 0)
	{
		*origin = add;
		return ;
	}
	o_tmp = *origin;
	a_tmp = add;
	*origin = gnl_strjoin(o_tmp, a_tmp);
	free(o_tmp);
	free(a_tmp);
}

int					get_line(int fd)
{
	static char		*buffer = 0;
	static ssize_t	size = BUFFER_SIZE;
	static int		index = 0;

	if (size == BUFFER_SIZE)
	{
		if((buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE))) == 0)
		{
			return (-1);
		}
		if ((size = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			printf("%s\n", buffer);
			return (0);
		}
	}
	index++;
	printf("%s\n", cut_buffer(&buffer, size));
	return (1);
}

int					main(void)
{
	int				fd;
	char			*tmp = "abcde";

	fd = open("test.txt", O_RDONLY);
	get_line(fd);
	//join_str(&tmp, "123");
	//tmp = gnl_strjoin(tmp, "1234");
	//printf("%s\n", tmp);
	return (0);
}
