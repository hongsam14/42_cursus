/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:46:02 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 12:04:59 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_vec	get_s_dist(t_vec ray, t_vec pos, t_vec *d_dist)
{
	t_vec	s_dist;
	t_vec	map;

	map.x = floor(pos.x);
	map.y = floor(pos.y);
	d_dist->x = fabs(1 / ray.x);
	d_dist->y = fabs(1 / ray.y);
	if (ray.x < 0)
		s_dist.x = (pos.x - map.x) * d_dist->x;
	else
		s_dist.x = (map.x + 1 - pos.x) * d_dist->x;
	if (ray.y < 0)
		s_dist.y = (pos.y - map.y) * d_dist->y;
	else
		s_dist.y = (map.y + 1 - pos.y) * d_dist->y;
	return (s_dist);
}

static double	get_perp_dist(t_vec map, t_vec pos, t_vec ray, int hor)
{
	double	dist;

	if (hor == 0)
	{
		if (ray.x < 0)
			dist = (map.x - pos.x + 1) / ray.x;
		else
			dist = (map.x - pos.x) / ray.x;
	}
	else
	{
		if (ray.y < 0)
			dist = (map.y - pos.y + 1) / ray.y;
		else
			dist = (map.y - pos.y) / ray.y;
	}
	return (dist);
}

static double	check_collision(t_vec ray, t_vec pos, t_world world, int *hor)
{
	t_vec	s_dist;
	t_vec	d_dist;
	t_vec	map;

	map.x = floor(pos.x);
	map.y = floor(pos.y);
	s_dist = get_s_dist(ray, pos, &d_dist);
	while (1)
	{
		if (s_dist.x < s_dist.y)
		{
			map.x++;
			*hor = 0;
			s_dist.x += d_dist.x;
		}
		else
		{
			map.y++;
			*hor = 1;
			s_dist.y += d_dist.y;
		}
		if (world.map_data[world.rows * (int)map.y + (int)map.x] == 1)
			break ;
	}
	return (get_perp_dist(map, pos, ray, *hor));
}

int	raycasting(t_game *game)
{
	t_vec	ray;
	int		i;
	int		hor;
	double	screen_x;
	double	dist;

	i = 0;
	//draw_sky_ground(&game->window, 0x010101, 0x101010);
	while (i < game->window.screen_w)
	{
		screen_x = i * 2 / (double)game->window.screen_w - 1;
		ray = multiply_s_vector(game->player.plane, screen_x);
		ray = add_vector(game->player.dir, ray);
		dist = check_collision(ray, game->player.pos, game->world, &hor);
		//draw texture.
		draw_col(&game->window, dist, i, hor);
		i++;
	}
	update_window(&game->window);
	return (0);
}
