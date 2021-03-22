/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:05:15 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 17:20:52 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		collider(t_game *game)
{
	t_vec	move;
	t_index	map;
	t_index	old_map;
	t_index	push;

	map = get_floor_vector(game->player.pos);
	if (game->world.map_data[map.y][map.x] == '1')
	{
		old_map = get_floor_vector(game->player.old_pos);
		move = subtract_vector(game->player.pos, game->player.old_pos);
		push = subtract_index(old_map, map);
		if (game->world.map_data[map.y][map.x + push.x] == '1')
			game->player.pos.y = game->player.old_pos.y;
		if (game->world.map_data[map.y + push.y][map.x] == '1')
			game->player.pos.x = game->player.old_pos.x;
	}
	game->player.old_pos = game->player.pos;
}
