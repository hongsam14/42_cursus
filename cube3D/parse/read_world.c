/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:54:10 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 22:09:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_s_f_c(char **word, t_world *world, t_window *win)
{
	if (ft_strnstr(word[0], "S", 1))
		return (load_texture(win, &world->sprite, word[1]));
	else if (ft_strnstr(word[0], "F", 1))
	{
		printf("floor\n");
	}
	else if (ft_strnstr(word[0], "C", 1))
	{
		printf("ceiling\n");
	}
	else
		return (0);
	return (1);
}

static int	check_direction(char **word, t_world *world, t_window *win)
{
	if (ft_strnstr(word[0], "NO", 2))
		return (load_texture(win, &world->wall_tex[0], word[1]));
	else if (ft_strnstr(word[0], "SO", 2))
		return (load_texture(win, &world->wall_tex[1], word[1]));
	else if (ft_strnstr(word[0], "WE", 2))
		return (load_texture(win, &world->wall_tex[3], word[1]));
	else if (ft_strnstr(word[0], "EA", 2))
		return (load_texture(win, &world->wall_tex[2], word[1]));
	else
		return (0);
	return (1);
}

static int	check_screen_size(char **word, t_window *window)
{
	int		w;
	int		h;
	
	if (ft_strnstr(word[0], "R", 1))
	{
		printf("screen\n");
		w = ft_atoi(word[1]);
		h = ft_atoi(word[2]);
		if (w <= 0 || h <= 0)
			return (0);
		window->screen_w = w;
		window->screen_h = h;
	}
	else
		return (0);
	return (1);
}

static int	read_word(char *line, t_world *world, t_window *win)
{
	int		index;
	int		debug;
	size_t	len;
	char	**word;

	debug = 1;
	index = get_word(line, &word, ' ');
	if (!index)
		return (0);
	len = ft_strlen(word[0]);
	if (index == 2)
	{
		if (len == 1)
			debug *= check_s_f_c(word, world, win);
		else if (len == 2)
			debug *= check_direction(word, world, win);
		else
			debug *= 0;
	}
	else if (index == 3 && len == 1)
		debug *= check_screen_size(word, win);
	while (index > 0)
		free(word[--index]);
	free(word);
	return (debug);
}

int			get_info(t_world *world, t_window *win, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_cubfile(file);
	if (fd < 0)
		return (0);
	line = 0;
	while (skip_empty_lines(fd, &line))
	{
		if (!read_word(line, world, win))
			return (0);
		free(line);
		line = 0;
	}
	free(line);
	close(fd);
	return (1);
}

int			get_map(t_world *world, t_window *win, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_cubfile(file);
	if (fd < 0)
		return (0);
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
	free(line);
	close(fd);
	return (1);
}
