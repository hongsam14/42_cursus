/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 22:11:48 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include <stdio.h>

int		init_game(t_game *game)
{
	init_window(&game->window);
	init_img(&game->window);
	init_control(&game->control);
	return (0);
}

void	get_control_info(t_game *game)
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
		turn_player_lr(&game->player, 1, 0.1);
	if (game->control.rotation & R_FLAG)
		turn_player_lr(&game->player, -1, 0.1);
}

int		main_loop(t_game *game)
{
	get_control_info(game);
	draw_sky_ground(&game->window, 0xFF00FF, 0x00FFFF);
	raycasting(game);
	update_window(&game->window);
	return (0);
}

int		main(void)
{
	t_game	game;
	int		map[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};
	
	game.window.screen_w = 600;
	game.window.screen_h = 400;
	game.player.dir.x = 0.5;
	game.player.dir.y = 0.5;
	game.player.pos.x = 2.5;
	game.player.pos.y = 2.5;
	game.player.plane.x = -0.5;
	game.player.plane.y = 0.5;
	game.world.rows = 5;
	game.world.cols = 5;
	game.world.map_data = (int *)malloc(sizeof(int) * 25);
	ft_memcpy(game.world.map_data, map, sizeof(int) * game.world.rows * game.world.cols);
	init_game(&game);
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_RELEASE, 1L<<1, &key_release, &game.control);
	mlx_loop_hook(game.window.mlx.mlx_ptr, &main_loop, &game);
	mlx_loop(game.window.mlx.mlx_ptr);
	return (0);
}
