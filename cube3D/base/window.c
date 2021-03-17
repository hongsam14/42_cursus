/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:48:56 by suhong            #+#    #+#             */
/*   Updated: 2021/03/13 17:38:24 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		init_window(t_window *window)
{
	int	max_w;
	int	max_h;

	window->mlx.mlx_ptr = mlx_init();
	if (!window->mlx.mlx_ptr)
		return (0);
	mlx_get_screen_size(window->mlx.mlx_ptr, &max_w, &max_h);
	if (!max_w || !max_h)
		return (0);
	if (window->screen_w > max_w)
		window->screen_w = max_w;
	if (window->screen_h > max_h)
		window->screen_h = max_h;
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
