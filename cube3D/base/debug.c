/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:07:29 by suhong            #+#    #+#             */
/*   Updated: 2021/03/24 15:33:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		ft_debug(int code, t_window *window)
{
	if (code > 0)
		return (1);
	printf("//////////\n");
	if (code == (int)ERROR_INIT_GAME)
		perror("Error\ninit_error:window.c : init_game");
	if (code == (int)ERROR_INIT_SIGHT)
		perror("Error\nmalloc_error:screen.c : init_sight");
	if (code == (int)ERROR_W_COLLISION)
		perror("Error\nraycast_error:wall_collision.c");
	if (code == (int)ERROR_W_TEXTURE)
		perror("Error\nray_cast_error:draw_wall.c : select_wall_tex");
	if (code == (int)ERROR_S_CHECK_POOL)
		perror("Error\nmalloc_error:sprite_collision.c : check_pool");
	if (code == (int)ERROR_OPEN_FILE)
		perror("Error\nfile_open_error:read_world.c : get_info");
	if (code == (int)ERROR_ELEMENT)
		perror("Error\nelement_error:check element");
	if (code == (int)ERROR_MAP)
		perror("Error\nmap_error:check map");
	if (code == (int)ERROR_LOAD_DATA)
		perror("Error\nmalloc_error:parse.c:load_data_2_world");
	printf("//////////\n");
	return (destroy_window(window));
}
