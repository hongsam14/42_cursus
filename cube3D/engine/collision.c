/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:46:02 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 16:57:28 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void		get_collision_info(t_ray *ray)
{
	if (ray->info & (0xFFFF << 16))
	{
		if (ray->ray.x < 0)
			ray->info |= INFO_EAST;
		else
			ray->info |= INFO_WEST;
	}
	else
	{
		if (ray->ray.y < 0)
			ray->info |= INFO_SOUTH;
		else
			ray->info |= INFO_NORTH;
	}
}

static double	get_perp_dist(t_index map, t_vec pos, t_ray *ray)
{
	get_collision_info(ray);
	if (ray->info & (0xFFFF << 16))
	{
		if (ray->ray.x < 0)
			ray->dist = (map.x - pos.x + 1) / ray->ray.x;
		else
			ray->dist = (map.x - pos.x) / ray->ray.x;
	}
	else
	{
		if (ray->ray.y < 0)
			ray->dist = (map.y - pos.y + 1) / ray->ray.y;
		else
			ray->dist = (map.y - pos.y) / ray->ray.y;
	}
	return (ray->dist);
}

double			collision(t_ray *ray, t_vec pos, t_world world, int **pool)
{
	t_vec		s_dist;
	t_vec		d_dist;
	t_index		map;

	d_dist = get_delta_dst(ray->ray);
	s_dist = get_side_dst(ray->ray, pos, d_dist, &map);
	while (map.x < world.w && map.x >= 0 && map.y < world.h && map.y >= 0)
	{
		move_dda(&map, &s_dist, d_dist, ray);
		if (world.map_data[map.y][map.x] == '1')
			return (get_perp_dist(map, pos, ray));
		update_pool(map.x, map.y, pool, world);
	}
	return (0);
}
