/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:36:58 by suhong            #+#    #+#             */
/*   Updated: 2021/03/23 19:37:57 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*get_map_node(t_data *data, t_index pos)
{
	char	*c;

	c = 0;
	if (pos.y >= 0 && pos.y < data->map_h && pos.x >= 0 && pos.x < data->map_w)
		c = &data->map[pos.y][pos.x];
	return (c);
}

t_index		get_circle_index(t_index pos, int i)
{
	t_index	index;
	int		x[8];
	int		y[8];

	x[0] = -1;
	x[1] = -1;
	x[2] = 0;
	x[3] = 1;
	x[4] = 1;
	x[5] = 1;
	x[6] = 0;
	x[7] = -1;
	y[0] = 0;
	y[1] = 1;
	y[2] = 1;
	y[3] = 1;
	y[4] = 0;
	y[5] = -1;
	y[6] = -1;
	y[7] = -1;
	index.x = x[i];
	index.y = y[i];
	return (add_index(pos, index));
}
