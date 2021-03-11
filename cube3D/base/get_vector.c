/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 03:39:11 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 18:48:16 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_vec		get_vertical_vector(t_vec dest)
{
	t_vec	v_vec;

	v_vec.x = dest.y;
	v_vec.y = -dest.x;
	return (v_vec);
}

t_vec		get_floor_vector(t_vec dest)
{
	t_vec	tmp;

	tmp.x = floor(dest.x);
	tmp.y = floor(dest.y);
	return (tmp);
}

double		get_vector_length(t_vec dest)
{
	double	len;

	len = sqrt(dest.x * dest.x + dest.y * dest.y);
	return (len);
}
