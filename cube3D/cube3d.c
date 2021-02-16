/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:48 by suhong            #+#    #+#             */
/*   Updated: 2021/02/14 04:19:55 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include <stdio.h>

int			main(void)
{
	t_window	window;
	t_player	player;

	window.width = 600;
	window.height = 400;
	player.dir.x = 0;
	player.dir.y = 1;
	player.pos.x = 1;
	player.pos.y = 2;
	player.plane.x = 1;
	player.plane.y = 0;
	init_window(&window);
	mlx_hook(window.mlx.window, X_EVENT_KEY_PRESS, 1L<<0, &control_player, &player);
	mlx_hook(window.mlx.window, X_EVENT_KEY_RELEASE, 1L<<1, &press_esc, &window);
	mlx_loop(window.mlx.mlx_ptr);
	return (0);
}
