/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:05:12 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 20:38:02 by suhong           ###   ########.fr       */
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

void			update_pool(int x, int y, int **pool, t_world wld)
{
	if (wld.map_data[y][x] == '2')
	{
		if (pool[y][x] == 0)
		{
			pool[y][x] = 1;
		}
	}
}
