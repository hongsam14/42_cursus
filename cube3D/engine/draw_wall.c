/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:03:31 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 20:51:22 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_tex	*select_wall_tex(t_world *world, int info)
{
	if (info & INFO_NORTH)
		return (&world->wall_tex[0]);
	if (info & INFO_SOUTH)
		return (&world->wall_tex[1]);
	if (info & INFO_EAST)
		return (&world->wall_tex[2]);
	if (info & INFO_WEST)
		return (&world->wall_tex[3]);
	return (0);
}

static int		get_tex_index_w(t_ray ray, t_vec player_pos, t_tex *tex)
{
	double		col_pos;
	int			index_w;

	if (ray.info & (0xFFFF << 16))
		col_pos = player_pos.y + ray.dist * ray.ray.y;
	else
		col_pos = player_pos.x + ray.dist * ray.ray.x;
	col_pos -= floor(col_pos);
	index_w = (int)(col_pos * (double)tex->tex_w);
	if ((ray.info & INFO_WEST) || (ray.info & INFO_SOUTH))
		index_w = tex->tex_w - index_w - 1;
	return (index_w);
}

static int		get_tex_index_h(int len, int pixel, t_window window, t_tex *tex)
{
	double		step;
	double		tex_pos;
	int			index_h;

	step = 1.0 * tex->tex_w / len;
	tex_pos = (pixel - window.screen_h / 2 + len / 2) * step;
	index_h = (int)tex_pos % tex->tex_h;
	return (index_h);
}

static void		get_draw_point(int *start, int *end, int screen_h, int len)
{
	*start = screen_h / 2 - len / 2;
	if (*start < 0)
		*start = 0;
	*end = screen_h / 2 + len / 2;
	if (*end >= screen_h)
		*end = screen_h - 1;
}

int				draw_wall(t_game *game, t_ray *ray, int r_index)
{
	int			length;
	int			draw_start;
	int			draw_end;
	int			index_w;
	t_tex		*tex;

	ray->dist = wall_collision(ray, game->player.pos, game->world, 1);
	if (!ray->dist)
		return (ERROR_W_COLLISION);
	length = (int)game->window.screen_h / ray->dist;
	get_draw_point(&draw_start, &draw_end, game->window.screen_h, length);
	tex = select_wall_tex(&game->world, ray->info);
	if (!tex)
		return (ERROR_W_TEXTURE);
	index_w = get_tex_index_w(*ray, game->player.pos, tex);
	while (draw_start <= draw_end)
	{
		game->window.img.data[game->window.screen_w * draw_start + r_index] =
			tex->img.data[tex->tex_w
			* get_tex_index_h(length, draw_start, game->window, tex) + index_w];
		draw_start++;
	}
	return (OK);
}
