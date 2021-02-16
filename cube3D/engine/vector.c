/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:35:44 by suhong            #+#    #+#             */
/*   Updated: 2021/02/13 19:52:13 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec		add_vector(t_vec dest, t_vec src)
{
	dest.x += src.x;
	dest.y += src.y;
	return (dest);
}

t_vec		multiply_s_vector(t_vec dest, double src)
{
	dest.x *= src;
	dest.y *= src;
	return (dest);
}

t_vec		get_vertical_vector(t_vec dest)
{
	t_vec	v_vec;

	v_vec.x = -dest.y;
	v_vec.y = dest.x;
	return (dest);
}
