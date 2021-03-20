/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 20:06:50 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void		init_game(t_game *game, t_data *data, char *dir, char *dir_2)
{
	int		debug;

	debug = 1;
	init_game_struct(game);
	debug *= get_map(&game->world, &game->window, dir);
	debug *= get_info(data, dir_2);
	debug *= load_screen_size_data(data, &game->window);
	debug *= init_engine(game);
	debug *= load_text_from_data(data, &game->world, &game->window);
	debug *= load_color_data(data, &game->world);
	if (!debug)
		ft_debug(ERROR_PARSING_FILE, &game->window);
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
	game.player.pos.x = 2.5;
	game.player.pos.y = 2.5;
	game.player.plane.x = 1;
	game.player.plane.y = 0;
	game.player.old_pos.x = 0;
	game.player.old_pos.y = 0;
	game.world.w = 11;
	game.world.h = 10;

	init_game(&game, &data, "map.cub", "set.cub");
	
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_RELEASE, 1L<<1, &key_release, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_EXIT, 1L<<17, &destroy_window, &game.window);
	mlx_loop_hook(game.window.mlx.mlx_ptr, &main_loop, &game);
	mlx_loop(game.window.mlx.mlx_ptr);
	return (0);
}
