/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/03/13 17:42:47 by suhong           ###   ########.fr       */
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
	int	map[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
		1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
		1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};
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

	game.world.map_data = (int *)malloc(sizeof(int) * game.world.w * game.world.h);
	ft_memcpy(game.world.map_data, map, sizeof(int) * game.world.w * game.world.h);

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
