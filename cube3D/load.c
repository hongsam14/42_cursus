/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:32:53 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 20:09:45 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_text_from_data(t_data *data, t_world *world, t_window *win)
{
	int		debug;

	debug = 1;
	debug *= load_texture(win, &world->wall_tex[0], data->wall_tex[0]);
	free(data->wall_tex[0]);
	debug *= load_texture(win, &world->wall_tex[1], data->wall_tex[1]);
	free(data->wall_tex[1]);
	debug *= load_texture(win, &world->wall_tex[2], data->wall_tex[2]);
	free(data->wall_tex[2]);
	debug *= load_texture(win, &world->wall_tex[3], data->wall_tex[3]);
	free(data->wall_tex[3]);
	debug *= load_texture(win, &world->sprite, data->sprite_tex);
	free(data->sprite_tex);
	return (debug);
}

static int	load_color_data(t_data *data, t_world *world)
{
	world->f = data->f;
	world->c = data->c;
	return (1);
}

static int	load_map_data(t_data *data, t_world *world)
{
	int		i;

	i = 0;
	world->w = data->map_w;
	world->h = data->map_h;
	printf("%d, %d\n", world->w, world->h);
	world->map_data = (char **)malloc(sizeof(char *) * data->map_h);
	if (!world->map_data)
		return (0);
	while (i < data->map_h)
	{
		world->map_data[i] = ft_strdup(data->map[i]);
		if (!world->map_data[i])
			return (0);
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (1);
}

void		load_world_init_data(t_data *data, t_game *game)
{
	game->window.screen_w = data->screen_w;
	game->window.screen_h = data->screen_h;
	if (!load_map_data(data, &game->world))
		ft_debug(ERROR_LOAD_DATA, &game->window);
}

void		load_data_2_world(t_data *data, t_game *game)
{
	int		debug;

	debug = 1;
	debug *= load_color_data(data, &game->world);
	debug *= load_text_from_data(data, &game->world, &game->window);
	if (!debug)
		ft_debug(ERROR_LOAD_DATA, &game->window);
}
