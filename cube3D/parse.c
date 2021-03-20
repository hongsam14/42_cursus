/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:32:53 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 12:53:59 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		load_screen_size_data(t_data *data, t_window *win)
{
	win->screen_w = data->screen_w;
	win->screen_h = data->screen_h;
	return (1);
}

int		load_text_from_data(t_data *data, t_world *world, t_window *win)
{
	int	debug;

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

int		load_color_data(t_data *data, t_world *world)
{
	world->f = data->f;
	world->c = data->c;
	return (1);
}
