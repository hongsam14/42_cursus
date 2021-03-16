/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:54:10 by suhong            #+#    #+#             */
/*   Updated: 2021/03/16 22:06:39 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			open_cubfile(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int			skip_empty_lines(int fd, char **line)
{
	int		result;
	
	result = get_next_line(fd, line); 
	while (**line == '\n' && result > 0)
		result = get_next_line(fd, line);
	return (result);
}

int			get_map(t_world *world, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_cubfile(file);
	line = 0;
	i = 0;
	world->map_data = (char **)malloc(sizeof(char *) * world->h);
	while (skip_empty_lines(fd, &line))
	{
		world->map_data[i] = (char *)malloc(sizeof(char) * world->w);
		ft_memcpy(world->map_data[i], line, world->w);
		free(line);
		line = 0;
		i++;
	}
	return (1);
}
