/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:07:29 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 16:41:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		ft_debug(int code)
{
	if (code < 0)
	{
		if (code == (int)ERROR_W_COLLISION)
			perror("raycast_error:wall_collision.c");
		if (code == (int)ERROR_W_TEXTURE)
			perror("ray_cast_error:draw_wall_texture.c : select_wall_tex");
		return (0);
	}
	return (1);
}
