/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:03:31 by suhong            #+#    #+#             */
/*   Updated: 2021/02/26 22:39:24 by suhong           ###   ########.fr       */
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

static int		get_tex_index_w(double dist, t_vec ray, int info, t_game game)
{
	double		col_pos;
	int			index_w;
	t_tex		*tex;

	tex = select_wall_tex(&game.world, info);
	if (info & (0xFFFF << 16))
		col_pos = game.player.pos.y + dist * ray.y;
	else
		col_pos = game.player.pos.x + dist * ray.x;
	col_pos -= floor(col_pos);
	index_w = (int)(col_pos * (double)tex->tex_w);
	if ((info & INFO_WEST) || (info & INFO_SOUTH))
		index_w = tex->tex_w - index_w - 1;
	return (index_w);
}

static int		get_tex_index_h(int len, int index, int info, t_game game)
{
	double		step;
	double		tex_pos;
	int			index_h;
	t_tex		*tex;

	tex = select_wall_tex(&game.world, info);
	step = 1.0 * tex->tex_w / len;
	tex_pos = (index - game.window.screen_h / 2 + len / 2) * step;
	index_h = (int)tex_pos & (tex->tex_h - 1);
	return (index_h);
}

void			draw_wall(t_game *game, t_vec ray, int r_index)
{
	int			info;
	int			length;
	int			draw_start;
	int			draw_end;
	double		dist;

	int			index_w;
	int			index_h;
	t_tex		*tex;

	dist = check_collision(ray, *game, &info);
	length = (int)game->window.screen_h / dist;
	draw_start = game->window.screen_h / 2 - length / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = game->window.screen_h / 2 + length / 2;
	if (draw_end >= game->window.screen_h)
		draw_end = game->window.screen_h - 1;
	
	tex = select_wall_tex(&game->world, info);
	index_w = get_tex_index_w(dist, ray, info, *game);
	
	while (draw_start <= draw_end)
	{
		index_h = get_tex_index_h(length, draw_start, info, *game);
		game->window.img.data[game->window.screen_w * draw_start + r_index]
			= tex->img.data[tex->tex_w * index_h + index_w];
			//= 0xEAE3C8;
		draw_start++;
	}
}
