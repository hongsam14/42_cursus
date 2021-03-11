/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:09:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 14:29:33 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_vec		get_delta_dist(t_vec ray)
{
	t_vec	d_dist;

	d_dist.x = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
	d_dist.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));
	return (d_dist);
}

t_vec		get_side_dist(t_vec ray, t_vec pos, t_vec d_dist, t_vec *map)
{
	t_vec	s_dist;

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

void		move_by_dda(t_vec *map, t_vec *s_dist, t_vec d_dist, t_ray *ray)
{
	t_vec	step;

	if (ray->ray.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray->ray.y < 0)
		step.y = -1;
	else
		step.y = 1;
	if (s_dist->x < s_dist->y)
	{
		map->x += step.x;
		ray->info |= (0xFFFF << 16);
		s_dist->x += d_dist.x;
	}
	else
	{
		map->y += step.y;
		ray->info &= ~(0xFFFF << 16);
		s_dist->y += d_dist.y;
	}
}
