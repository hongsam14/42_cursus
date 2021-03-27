/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:13:51 by suhong            #+#    #+#             */
/*   Updated: 2021/03/28 02:21:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game)
{
	game->window.mlx.mlx_ptr = 0;
	game->window.mlx.window = 0;
	game->window.img.img_ptr = 0;
	game->window.img.data = 0;
}

void	move_player(t_game *game)
{
	control_player(game);
	collider(game);
}

int		init_engine(t_game *game)
{
	int	debug;

	debug = 1;
	debug *= init_mlx(&game->window);
	debug *= init_img(&game->window);
	if (!game->bmp)
		debug *= init_window(&game->window);
	init_control(&game->control);
	if (!debug)
		return (ft_debug(ERROR_INIT_GAME, &game->window));
	return (init_sight(game));
}

void	draw_scene(t_game *game)
{
	draw_sky_ground(&game->window, game->world.f, game->world.c);
	raycasting(game);
}
