/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:54:10 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 21:19:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int		check_s_f_c(char **word, t_data *data)
{
	int			index;
	int			color;

	if (ft_strnstr(word[0], "S", 1))
	{
		data->sprite_tex = ft_strdup(word[1]);
		if (!data->sprite_tex)
			return (0);
		return (TEXTURE_SPRITE);
	}
	else if (get_rgb(word[1], &color))
	{
		if (ft_strnstr(word[0], "F", 1))
		{
			data->f = color;
			return (F_COLOR);
		}
		if (ft_strnstr(word[0], "C", 1))
		{
			data->c = color;
			return (C_COLOR);
		}
	}
	return (0);
}

static int		check_direction(char **word, t_data *data)
{
	static int	result = 0;
	int			i;
	char		*tmp;

	tmp = ft_strdup(word[1]);
	if (!tmp)
		return (0);
	if (ft_strnstr(word[0], "NO", 2))
		i = 0;
	else if (ft_strnstr(word[0], "SO", 2))
		i = 1;
	else if (ft_strnstr(word[0], "WE", 2))
		i = 3;
	else if (ft_strnstr(word[0], "EA", 2))
		i = 2;
	else
		return (0);
	if (data->wall_tex[i])
		return (0);
	data->wall_tex[i] = tmp;
	result |= (0x1 << 16) << (4 * i);
	return (result);
}

static int		check_screen_size(char **word, t_data *data)
{
	int			w;
	int			h;

	if (ft_strnstr(word[0], "R", 1))
	{
		if (!check_str(word[1], "0123456789")
				|| !check_str(word[2], "0123456789"))
			return (0);
		w = ft_atoi(word[1]);
		h = ft_atoi(word[2]);
		if (w <= 0 || h <= 0)
			return (0);
		data->screen_w = w;
		data->screen_h = h;
	}
	else
		return (0);
	return (SCREEN);
}

static int		read_word(char *line, t_data *data)
{
	int			index;
	int			debug;
	size_t		len;
	char		**word;

	index = get_word(line, &word, ' ');
	debug = 0;
	if (!index)
		return (0);
	len = ft_strlen(word[0]);
	if (index == 2)
	{
		if (len == 1)
			debug = check_s_f_c(word, data);
		else if (len == 2)
			debug = check_direction(word, data);
	}
	else if (index == 3 && len == 1)
		debug = check_screen_size(word, data);
	while (index > 0)
		free(word[--index]);
	free(word);
	return (debug);
}

int				get_info(t_data *data, char *file)
{
	int			fd;
	int			i;
	char		*line;
	int			debug;
	int			out;

	if (!open_cubfile(file, &fd))
		return (ERROR_OPEN_FILE);
	line = 0;
	out = 0;
	while (skip_empty_lines(fd, &line))
	{
		debug = read_word(line, data);
		if (!debug)
			return (ERROR_ELEMENT);
		printf("%s\n", line);
		out |= debug;
		free(line);
		line = 0;
		if ((out & SCREEN) && (out & F_COLOR) && (out & C_COLOR)
				&& (out & TEXTURE_SPRITE)
				&& ((out & TEXTURE_WALL) == TEXTURE_WALL))
			break ;
	}
	return (make_square_map(fd, &data->map_w, &data->map_h, &data->map));
}
