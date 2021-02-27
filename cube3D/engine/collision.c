/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:46:02 by suhong            #+#    #+#             */
/*   Updated: 2021/02/27 17:11:50 by suhong           ###   ########.fr       */
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
			ray->info |= INFO_NORTH;
		else
			ray->info |= INFO_SOUTH;
	}
}

static double	get_perp_dist(t_vec map, t_vec pos, t_ray *ray)
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

double			check_collision(t_ray *ray, t_vec pos, t_world world, int obj)
{
	t_vec		s_dist;
	t_vec		d_dist;
	t_vec		map;
	t_vec		step;

	d_dist = get_d_dist(ray->ray, &step);
	s_dist = get_s_dist(ray->ray, pos, d_dist, &map);
	while (map.x < world.rows && map.x >= 0 && map.y < world.cols && map.y >= 0)
	{
		if (s_dist.x < s_dist.y)
		{
			map.x += step.x;
			ray->info |= (0xFFFF << 16);
			s_dist.x += d_dist.x;
		}
		else
		{
			map.y += step.y;
			ray->info &= ~(0xFFFF << 16);
			s_dist.y += d_dist.y;
		}
		if (world.map_data[world.rows * (int)map.y + (int)map.x] == obj)
			return (get_perp_dist(map, pos, ray));
	}
	return (0);
}
