/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:21 by suhong            #+#    #+#             */
/*   Updated: 2021/02/26 22:32:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_sky_ground(t_window *window, int sky, int ground)
{
	int	i;

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

void	draw_col(t_window *window, double dist, int r_index, int hor)
{
	int	draw_start;
	int	draw_end;
	int	length;

	length = (int)window->screen_h / dist;
	draw_start = window->screen_h / 2 - length / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = window->screen_h / 2 + length / 2;
	if (draw_end >= window->screen_h)
		draw_end = window->screen_h - 1;
	while (draw_start <= draw_end)
	{
#if 1
		if (hor & (0xFFFF << 16))
			window->img.data[window->screen_w * draw_start
				+ r_index] = 0xEAE3C8;
		else
			window->img.data[window->screen_w * draw_start
				+ r_index] = 0xCFC5A5;
#endif
		draw_start++;
	}
}

void			raycasting(t_game *game)
{
    t_vec		ray;
    int			i;
    int			info;
    double		screen_x;
    double		dist;

    i = 0;
    while (i < game->window.screen_w)
    {
		info = 0;
        screen_x = 2 * i / (double)game->window.screen_w - 1;
        ray = multiply_s_vector(game->player.plane, screen_x);
        ray = add_vector(game->player.dir, ray);
        //dist = check_collision(ray, *game, &info);
        //draw_col(&game->window, dist, i, info);
		draw_wall(game, ray, i);
        i++;
    }
}
