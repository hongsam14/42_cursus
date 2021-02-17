/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:21 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 20:38:42 by suhong           ###   ########.fr       */
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
		if (hor == 1)
			window->img.data[window->screen_w * draw_start
				+ r_index] = 0xffffff;
		else
			window->img.data[window->screen_w * draw_start
				+ r_index] = 0xF8F8F8;
		draw_start++;
	}
}
