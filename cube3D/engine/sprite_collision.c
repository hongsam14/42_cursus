/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:53:52 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 20:51:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_sprite	*init_sprite(t_vec map, t_vec pos)
{
	t_sprite	*tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	if (!tmp)
		return (0);
	tmp->pos = map;
	tmp->dist = (map.x - pos.x) * (map.x - pos.x)
		+ (map.y - pos.y) * (map.y - pos.y);
	tmp->next = 0;
	return (tmp);
}

static void		*clean_sprite_list(t_sprite *s_list)
{
	t_sprite	*start;
	t_sprite	*tmp;

	start = s_list;
	while (s_list)
	{
		tmp = s_list->next;
		free(s_list);
		s_list = tmp;
	}
	free(start);
	return (0);
}

static t_sprite	*add_sprite_list(t_vec map, t_vec pos, t_sprite *s_list)
{
	t_sprite	*tmp;
	t_sprite	*old;
	t_sprite	*add;

	add = init_sprite(map, pos);
	if (!add)
		return (clean_sprite_list(s_list));
	if (!s_list)
		return (add);
	tmp = s_list;
	old = 0;
	while (tmp && tmp->dist > add->dist)
	{
		old = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		old->next = add;
	else
	{
		if (old)
			old->next = add;
		add->next = tmp;
	}
	return (s_list);
}

int				sprite_collision(t_ray *ray, t_vec pos, t_world world
		, t_sprite *list)
{
	t_vec		s_dist;
	t_vec		d_dist;
	t_vec		map;
	int			obj;

	d_dist = get_delta_dist(ray->ray);
	s_dist = get_side_dist(ray->ray, pos, d_dist, &map);
	obj = 0;
	while (obj != 1)
	{
		move_by_dda(&map, &s_dist, d_dist, ray);
		obj = world.map_data[world.rows * (int)map.y + (int)map.x];
		if (obj == 2)
		{
			list = add_sprite_list(map, pos, list);
			if (!list)
				return (-1);
		}
	}
	return (1);
}
