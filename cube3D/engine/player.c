/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:47:46 by suhong            #+#    #+#             */
/*   Updated: 2021/03/23 19:33:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	move_player_fb(t_player *player, int dir, double speed)
{
	t_vec	dir_vec;

	dir_vec = multiply_s_vector(player->dir, dir * speed);
	player->pos = add_vector(player->pos, dir_vec);
}

static void	move_player_lr(t_player *player, int dir, double speed)
{
	t_vec	plane_vec;

	plane_vec = multiply_s_vector(player->plane, dir * speed);
	player->pos = add_vector(player->pos, plane_vec);
}

static void	turn_player_lr(t_player *player, int dir, double speed)
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

void		control_player(t_game *game)
{
	if (game->control.movement & W_FLAG)
		move_player_fb(&game->player, 1, 0.1);
	if (game->control.movement & S_FLAG)
		move_player_fb(&game->player, -1, 0.1);
	if (game->control.movement & A_FLAG)
		move_player_lr(&game->player, -1, 0.1);
	if (game->control.movement & D_FLAG)
		move_player_lr(&game->player, 1, 0.1);
	if (game->control.rotation & L_FLAG)
		turn_player_lr(&game->player, -1, 0.1);
	if (game->control.rotation & R_FLAG)
		turn_player_lr(&game->player, 1, 0.1);
	if (game->control.exit & ESC_FLAG)
		destroy_window(&game->window);
}
