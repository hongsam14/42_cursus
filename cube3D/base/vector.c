/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:35:44 by suhong            #+#    #+#             */
/*   Updated: 2021/02/19 03:44:40 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_vec		add_vector(t_vec dest, t_vec src)
{
	dest.x += src.x;
	dest.y += src.y;
	return (dest);
}

t_vec		subtract_vector(t_vec dest, t_vec src)
{
	dest.x -= src.x;
	dest.y -= src.y;
	return (dest);
}

t_vec		multiply_s_vector(t_vec dest, double src)
{
	dest.x *= src;
	dest.y *= src;
	return (dest);
}
