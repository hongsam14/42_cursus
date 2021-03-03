/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:21 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 19:59:26 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		draw_sky_ground(t_window *window, int sky, int ground)
{
	int		i;

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

int			raycasting(t_game *game)
{
	t_ray	*ray;
	int		debug;
	int		i;
	double	screen_x;

	i = 0;
	debug = 1;
	ray = (t_ray *)malloc(sizeof(t_ray) * game->window.screen_w);
	if (!ray)
		debug *= 0;
	while (i < game->window.screen_w && debug)
	{
		ray[i].info = 0;
		screen_x = 2 * i / (double)game->window.screen_w - 1;
		ray[i].ray = multiply_s_vector(game->player.plane, screen_x);
		ray[i].ray = add_vector(game->player.dir, ray[i].ray);
		debug *= ft_debug(draw_wall(game, &ray[i], i));
		i++;
	}
	free(ray);
	return (debug);
}
