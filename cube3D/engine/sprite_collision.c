/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:05:12 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 17:44:43 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void			init_pool(int **pool, t_world world)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < world.h)
	{
		x = 0;
		while (x < world.w)
		{
			pool[y][x] = 0;
			x++;
		}
		y++;
	}
}

void			update_pool(int **pool, t_ray *ray, t_vec pos, t_world world)
{
	t_vec		s_dist;
	t_vec		d_dist;
	t_vec		map;

	d_dist = get_delta_dist(ray->ray);
	s_dist = get_side_dist(ray->ray, pos, d_dist, &map);
	while (world.map_data[world.w * (int)map.y + (int)map.x] != 1)
	{
		move_by_dda(&map, &s_dist, d_dist, ray);
		if (world.map_data[world.w * (int)map.y + (int)map.x] == 2)
		{
			if (pool[(int)map.y][(int)map.x] == 0)
			{
				pool[(int)map.y][(int)map.x] = 1;
			}
		}
	}
}
