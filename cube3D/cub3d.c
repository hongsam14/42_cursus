/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 21:04:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_game(t_game *game, t_data *data, char *file)
{
	init_game_struct(game);
	init_data_struct(data);
	parse(data, &game->window, file);
	load_world_init_data(data, game);
	init_engine(game);
	load_data_2_world(data, game);
}

int			main_loop(t_game *game)
{
	move_player(game);
	draw_scene(game);
	update_window(&game->window);
	return (0);
}

int			main(void)
{
	t_game	game;
	t_data	data;
	
	game.player.dir.x = 0;
	game.player.dir.y = 1;
	game.player.pos.x = 8;
	game.player.pos.y = 4;
	game.player.plane.x = 1;
	game.player.plane.y = 0;
	game.player.old_pos.x = 0;
	game.player.old_pos.y = 0;

	init_game(&game, &data, "set.cub");
	
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_RELEASE, 1L<<1, &key_release, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_EXIT, 1L<<17, &destroy_window, &game.window);
	mlx_loop_hook(game.window.mlx.mlx_ptr, &main_loop, &game);
	mlx_loop(game.window.mlx.mlx_ptr);
	return (0);
}
