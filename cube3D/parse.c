/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:31:09 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 21:05:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_struct(t_data *data)
{
	data->f = 0;
	data->screen_w = 0;
	data->screen_h = 0;
	data->wall_tex[0] = 0;
	data->wall_tex[1] = 0;
	data->wall_tex[2] = 0;
	data->wall_tex[3] = 0;
	data->sprite_tex = 0;
	data->map_w = 0;
	data->map_h = 0;
	data->map = 0;
}

void	parse(t_data *data, t_window *window, char *file)
{
	ft_debug(get_info(data, file), window);
}
