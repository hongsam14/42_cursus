/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:46:02 by suhong            #+#    #+#             */
/*   Updated: 2021/02/26 21:47:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_vec	get_d_dist(t_vec ray, t_vec *step)
{
	t_vec		d_dist;

	d_dist.x = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
	d_dist.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));
	if (ray.x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (ray.y < 0)
		step->y = -1;
	else
		step->y = 1;
	return (d_dist);
}

static t_vec	get_s_dist(t_vec ray, t_vec pos, t_vec d_dist, t_vec *map)
{
	t_vec		s_dist;

	*map = get_floor_vector(pos);
	if (ray.x < 0)
		s_dist.x = (pos.x - map->x) * d_dist.x;
	else
		s_dist.x = (map->x + 1 - pos.x) * d_dist.x;
	if (ray.y < 0)
		s_dist.y = (pos.y - map->y) * d_dist.y;
	else
		s_dist.y = (map->y + 1 - pos.y) * d_dist.y;
	return (s_dist);
}

static void		get_collision_info(t_vec ray, int *info)
{
	if (*info & (0xFFFF << 16))
	{
		if (ray.x < 0)
			*info |= INFO_EAST;
		else
			*info |= INFO_WEST;
	}
	else
	{
		if (ray.y < 0)
			*info |= INFO_NORTH;
		else
			*info |= INFO_SOUTH;
	}
}

static double	get_perp_dist(t_vec map, t_vec pos, t_vec ray, int *info)
{
	double		dist;

	get_collision_info(ray, info);
	if (*info & (0xFFFF << 16))
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

double			check_collision(t_vec ray, t_game game, int *info)
{
	t_vec		s_dist;
	t_vec		d_dist;
	t_vec		map;
	t_vec		step;

	d_dist = get_d_dist(ray, &step);
	s_dist = get_s_dist(ray, game.player.pos, d_dist, &map);
	while (1)
	{
		if (s_dist.x < s_dist.y)
		{
			map.x += step.x;
			*info |= (0xFFFF << 16);
			s_dist.x += d_dist.x;
		}
		else
		{
			map.y += step.y;
			*info &= ~(0xFFFF << 16);
			s_dist.y += d_dist.y;
		}
		if (game.world.map_data[game.world.rows
				* (int)map.y + (int)map.x] == 1)
			break ;
	}
	return (get_perp_dist(map, game.player.pos, ray, info));
}
