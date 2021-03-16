/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:08:51 by suhong            #+#    #+#             */
/*   Updated: 2021/03/16 15:48:58 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int					get_color(int color, double dist, int info)
{
	int				r;
	int				g;
	int				b;
	int				out;

	out = 0x00000000;
	r = (color & (0xFF << 16)) >> 16;
	g = (color & (0xFF << 8)) >> 8;
	b = color & 0xFF;
	if (info & (0xFFFF << 16))
	{
		r = r >> 1;
		g = g >> 1;
		b = b >> 1;
	}
	out |= (r << 16) | (g << 8) | b;
	return (out);
	if (dist)
		return (out);
}
