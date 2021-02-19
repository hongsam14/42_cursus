/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:05:15 by suhong            #+#    #+#             */
/*   Updated: 2021/02/19 03:54:12 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		collider(t_game *game)
{
	t_vec	push;
	t_vec	move;
	t_vec	map;
	t_vec	old_map;

	map = get_floor_vector(game->player.pos);
	if (game->world.map_data[game->world.rows * (int)map.y + (int)map.x] == 1)
	{
		old_map = get_floor_vector(game->player.old_pos);
		move = subtract_vector(game->player.pos, game->player.old_pos);
		push = subtract_vector(old_map, map);
		push = multiply_s_vector(push, get_vector_length(move));
		game->player.pos = add_vector(game->player.pos, push);
	}
	game->player.old_pos = game->player.pos;
}

