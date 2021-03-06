/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:48:56 by suhong            #+#    #+#             */
/*   Updated: 2021/03/29 00:56:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		init_mlx(t_window *window)
{
	window->mlx.mlx_ptr = mlx_init();
	if (!window->mlx.mlx_ptr)
		return (0);
	return (1);
}

int		init_window(t_window *window)
{
	window->mlx.window = mlx_new_window(window->mlx.mlx_ptr,
				window->screen_w, window->screen_h, "cub3d");
	return (1);
}

int		init_img(t_window *window)
{
	window->img.img_ptr = mlx_new_image(window->mlx.mlx_ptr,
			window->screen_w, window->screen_h);
	if (!window->img.img_ptr)
		return (0);
	window->img.data = (int *)mlx_get_data_addr(window->img.img_ptr,
			&window->img.bpp, &window->img.size_l, &window->img.endian);
	return (1);
}

int		destroy_window(t_window *window)
{
	if (window->img.img_ptr && window->mlx.mlx_ptr)
		mlx_destroy_image(window->mlx.mlx_ptr, window->img.img_ptr);
	if (window->mlx.mlx_ptr && window->mlx.window)
		mlx_destroy_window(window->mlx.mlx_ptr, window->mlx.window);
	exit(0);
	return (0);
}

void	update_window(t_window *window)
{
	mlx_put_image_to_window(window->mlx.mlx_ptr, window->mlx.window,
			window->img.img_ptr, 0, 0);
}
