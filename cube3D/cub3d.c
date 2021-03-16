/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/03/16 22:06:36 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		main_loop(t_game *game)
{
	move_player(game);
	if (!draw_scene(game))
		destroy_window(&game->window);
	update_window(&game->window);
	return (0);
}

int		main(void)
{
	t_game	game;
	
	game.window.screen_w = 800;
	game.window.screen_h = 600;
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
	game.world.f = 0xA1CAE2;
	game.world.c = 0xC2B092;

	get_map(&game.world, "map.cub");
	if (!init_engine(&game))
		destroy_window(&game.window);

	load_texture(&game.window, &game.world.wall_tex[0], "texture/wood.xpm");
	load_texture(&game.window, &game.world.wall_tex[1], "texture/redbrick.xpm");
	load_texture(&game.window, &game.world.wall_tex[2], "texture/greystone.xpm");
	load_texture(&game.window, &game.world.wall_tex[3], "texture/colorstone.xpm");
	load_texture(&game.window, &game.world.sprite, "texture/barrel.xpm");

	mlx_hook(game.window.mlx.window, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_KEY_RELEASE, 1L<<1, &key_release, &game.control);
	mlx_hook(game.window.mlx.window, X_EVENT_EXIT, 1L<<17, &destroy_window, &game.window);
	mlx_loop_hook(game.window.mlx.mlx_ptr, &main_loop, &game);
	mlx_loop(game.window.mlx.mlx_ptr);
	return (0);
}
