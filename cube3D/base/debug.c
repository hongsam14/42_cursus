/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:07:29 by suhong            #+#    #+#             */
/*   Updated: 2021/03/06 16:07:47 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		ft_debug(int code)
{
	if (code < 0)
	{
		if (code == (int)ERROR_INIT_GAME)
			perror("init_error:window.c : init_game");
		if (code == (int)ERROR_INIT_SIGHT)
			perror("malloc_error:screen.c : init_sight");
		if (code == (int)ERROR_W_COLLISION)
			perror("raycast_error:wall_collision.c");
		if (code == (int)ERROR_W_TEXTURE)
			perror("ray_cast_error:draw_wall.c : select_wall_tex");
		if (code == (int)ERROR_S_CHECK_POOL)
			perror("malloc_error:sprite_collision.c : check_pool");
		return (0);
	}
	return (1);
}
