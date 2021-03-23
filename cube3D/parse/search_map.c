/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:13 by suhong            #+#    #+#             */
/*   Updated: 2021/03/23 18:50:32 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	search_map(t_data *data, t_index pos)
{
	int		i;
	char	*c;
	t_index	search;

	i = 0;
	c = get_map_node(data, pos);
	if (*c == '1' || *c == 'X')
		return (1);
	if (!c || *c == ' ')
		return (0);
	if (*c == '0' || ft_strchr("NSEW", *c))
		*c = 'X';
	while (i < 8)
	{
		search = get_circle_index(pos, i);
		if (!search_map(data, search))
			return (0);
		i++;
	}
	return (1);
}

static int	search_player_pos(t_data *data)
{
	t_index	index;
	char	c;

	index.y = 0;
	while (index.y < data->map_h)
	{
		index.x = 0;
		while (index.x < data->map_w)
		{
			c = data->map[index.y][index.x];
			if (ft_strchr("NSEW", c))
			{
				data->player_pos.x = index.x;
				data->player_pos.y = index.y;
				data->player_dir = c;
				return (1);
			}
			index.x++;
		}
		index.y++;
	}
	return (0);
}

int			judge_map(t_data *data)
{
	if (!search_player_pos(data))
		return (ERROR_MAP);
	if (!search_map(data, data->player_pos))
		return (ERROR_MAP);
	return (1);
}
