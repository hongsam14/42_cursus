/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:09:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 14:23:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_vec		get_delta_dst(t_vec ray)
{
	t_vec	d_dist;

	d_dist.x = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
	d_dist.y = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));
	return (d_dist);
}

t_vec		get_side_dst(t_vec ray, t_vec pos, t_vec d_dst, t_vec *map)
{
	t_vec	s_dst;

	*map = get_floor_vector(pos);
	if (ray.x < 0)
		s_dst.x = (pos.x - map->x) * d_dst.x;
	else
		s_dst.x = (map->x + 1 - pos.x) * d_dst.x;
	if (ray.y < 0)
		s_dst.y = (pos.y - map->y) * d_dst.y;
	else
		s_dst.y = (map->y + 1 - pos.y) * d_dst.y;
	return (s_dst);
}

void		move_dda(t_vec *map, t_vec *s_dst, t_vec d_dst, t_ray *ray)
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
	if (s_dst->x < s_dst->y)
	{
		map->x += step.x;
		ray->info |= (0xFFFF << 16);
		s_dst->x += d_dst.x;
	}
	else
	{
		map->y += step.y;
		ray->info &= ~(0xFFFF << 16);
		s_dst->y += d_dst.y;
	}
}
