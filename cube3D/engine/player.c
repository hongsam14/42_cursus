/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:47:46 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 21:51:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		move_player_fb(t_player *player, int dir, double speed)
{
	t_vec	dir_vec;

	dir_vec = multiply_s_vector(player->dir, dir * speed);
	player->pos = add_vector(player->pos, dir_vec);
}

void		move_player_lr(t_player *player, int dir, double speed)
{
	t_vec	plane_vec;

	plane_vec = multiply_s_vector(player->plane, dir * speed);
	player->pos = add_vector(player->pos, plane_vec);
}

void		turn_player_lr(t_player *player, int dir, double speed)
{
	t_vec	d_vec;
	double	angle;

	d_vec.x = player->dir.x;
	d_vec.y = player->dir.y;
	angle = dir * speed;
	player->dir.x = d_vec.x * cos(angle) - d_vec.y * sin(angle);
	player->dir.y = d_vec.x * sin(angle) + d_vec.y * cos(angle);
	player->plane = get_vertical_vector(player->dir);
}
