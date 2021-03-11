/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:05:12 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 01:27:22 by suhong           ###   ########.fr       */
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

static t_sprite	*init_list(int x, int y, t_vec pos)
{
	t_sprite	*add;

	add = (t_sprite *)malloc(sizeof(t_sprite));
	if (!add)
		return (0);
	add->pos.x = x + 0.5;
	add->pos.y = y + 0.5;
	add->dist = pow(add->pos.x - pos.x, 2) + pow(add->pos.y - pos.y, 2);
	add->next = 0;
	return (add);
}

static int		add_list(int x, int y, t_vec pos, t_sprite **list)
{
	t_sprite	*add;
	t_sprite	*tmp;
	t_sprite	*i;

	add = init_list(x, y, pos);
	if (!add)
		return (0);
	if (*list == 0)
	{
		*list = add;
		return (1);
	}
	i = *list;
	tmp = 0;
	while (i && add->dist < i->dist)
	{
		tmp = i;
		i = i->next;
	}
	if (!tmp)
		*list = add;
	else
		tmp->next = add;
	add->next = i;
	return (1);
}

int				check_pool(int **pool, t_vec pos, t_world world, t_sprite **list)
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
			if (pool[y][x] == 1)
			{
				if (!add_list(x, y, pos, list))
					return (ft_debug(ERROR_S_CHECK_POOL));
			}
			x++;
		}
		y++;
	}
	return (ft_debug(OK));
}
