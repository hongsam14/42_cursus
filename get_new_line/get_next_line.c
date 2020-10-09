/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:39:18 by suhong            #+#    #+#             */
/*   Updated: 2020/10/09 22:11:22 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int							get_next_line(int fd, char **line)
{
	static char	*tmp;
	static ssize_t			r_size;
	static char	*start;
	static int				i;

	tmp = (char *)malloc(BUFFER_SIZE);
	if (tmp == 0)
		return (-1);
	r_size = read(fd, tmp, BUFFER_SIZE);
	if (r_size < 0)
		return (-1);
	i = 0;
	start = tmp;
	start = (char *)gnl_memccpy(line[i], start, '\n', r_size);
	if (start)
	{
		r_size -= start - tmp;
		i++;
		return (1);
	}
	free(tmp);
	tmp = 0;
	return (0);
}
