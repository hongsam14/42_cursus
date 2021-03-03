/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:43:22 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 20:50:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	get_tex_index_w(t_sprite sprite, t_ray ray, t_vec pos, t_tex *tex)
{
	t_vec	s_center;

	s_center.x = sprite.pos.x + 0.5 - pos.x;
	s_center.y = sprite.pos.y + 0.5 - pos.y;
}
