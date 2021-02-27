/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:07:29 by suhong            #+#    #+#             */
/*   Updated: 2021/02/27 16:42:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		ft_debug(int code)
{
	if (code < 0)
	{
		if (code == ERROR_W_COLLISION)
			perror("raycast_error:collision.c");
		if (code == ERROR_WALL_TEXTURE)
			perror("ray_cast_error:draw_wall_texture.c : select_wall_tex");
		return (0);
	}
	return (1);
}
