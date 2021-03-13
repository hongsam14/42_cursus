/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:21 by suhong            #+#    #+#             */
/*   Updated: 2021/03/13 16:42:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void			draw_sky_ground(t_window *window, int sky, int ground)
{
	int			i;

	i = 0;
	while (i < window->screen_w * window->screen_h)
	{
		if (i < window->screen_w * window->screen_h / 2)
			window->img.data[i] = sky;
		else
			window->img.data[i] = ground;
		i++;
	}
}

int				init_sight(t_game *game)
{
	int			i;

	i = 0;
	game->sight.ray = (t_ray *)malloc(sizeof(t_ray) * game->window.screen_w);
	if (!game->sight.ray)
		return (ft_debug(ERROR_INIT_SIGHT));
	game->sight.pool = (int **)malloc(sizeof(int *) * game->world.h);
	if (!game->sight.pool)
		return (ft_debug(ERROR_INIT_SIGHT));
	while (i < game->world.h)
	{
		game->sight.pool[i] = (int *)malloc(sizeof(int) * game->world.w);
		if (!game->sight.pool[i])
			return (ft_debug(ERROR_INIT_SIGHT));
		i++;
	}
	return (ft_debug(OK));
}

int				raycasting(t_game *game)
{
	int			debug;
	int			i;
	double		screen_x;
	t_sprite	*list;

	i = 0;
	list = 0;
	debug = 1;
	init_pool(game->sight.pool, game->world);
	while (i < game->window.screen_w && debug)
	{
		game->sight.ray[i].info = 0;
		screen_x = 2 * i / (double)game->window.screen_w - 1;
		game->sight.ray[i].ray = multiply_s_vector(game->player.plane
				, screen_x);
		game->sight.ray[i].ray = add_vector(game->player.dir
				, game->sight.ray[i].ray);
		debug *= draw_wall(game, &game->sight.ray[i], i);
		update_pool(game->sight.pool, &game->sight.ray[i]
				, game->player.pos, game->world);
		i++;
	}
	debug *= check_pool(game->sight.pool, *game, &list);
	draw_sprites(&list, game);
	return (debug);
}
