/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:13:51 by suhong            #+#    #+#             */
/*   Updated: 2021/03/13 16:57:48 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game)
{
	control_player(game);
	collider(game);
}

int		init_engine(t_game *game)
{
	int	debug;

	debug = 1;
	//debug *= init_img(&game->window);
	debug *= init_window(&game->window);
	debug *= init_img(&game->window);
	init_control(&game->control);
	if (!debug)
		return (ft_debug(ERROR_INIT_GAME));
	
	return (init_sight(game));
}

int		draw_scene(t_game *game)
{
	draw_sky_ground(&game->window, game->world.f, game->world.c);
	if (!raycasting(game))
		return (0);
	return (1);
}
