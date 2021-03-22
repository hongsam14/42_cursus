/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:36:58 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 21:49:14 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*get_map_node(t_data *data, t_index pos)
{
	char	*c;
	
	c = 0;
	if (pos.y >= 0 && pos.y < data->map_h
			&& pos.x >= 0  && pos.x < data->map_w)
		c = &data->map[pos.y][pos.x];
	return (c);
}

t_index		get_circle_index(t_index pos, int i)
{
	t_index	index;

	index.x = {-1, -1, 0, 1, 1, 1, 0, -1}[i];
	index.y = {0, 1, 1, 1, 0, -1, -1, -1}[i];
	return (add_index(pos, index));
}
