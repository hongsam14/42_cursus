/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:53:36 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 18:24:56 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int				load_texture(t_window *window, t_tex *tex, char *path)
{
	if (path)
	{
		tex->img.img_ptr = mlx_xpm_file_to_image(window->mlx.mlx_ptr,
				path, &tex->tex_w, &tex->tex_h);
		if (tex->img.img_ptr)
		{
			tex->img.data = (int *)mlx_get_data_addr(tex->img.img_ptr,
					&tex->img.bpp, &tex->img.size_l, &tex->img.endian);
			if (tex->img.data)
				return (1);
		}
	}
	return (0);
}
