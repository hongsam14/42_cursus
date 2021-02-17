/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 12:05:46 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include <stdio.h>

int			main(void)
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
	init_window(&game.window);
	init_img(&game.window);
	mlx_loop_hook(game.window.mlx.mlx_ptr, &raycasting, &game);
	mlx_loop(game.window.mlx.mlx_ptr);
	return (0);
}
