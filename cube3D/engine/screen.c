/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:33:21 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 00:26:59 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "engine.h"

void	draw_col(t_window *window, double dist, int r_index)
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
		window->img.data[] = 0xffffff;
		draw_start++;
	}
}
