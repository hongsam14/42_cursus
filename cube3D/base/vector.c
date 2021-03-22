/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:35:44 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 17:19:18 by suhong           ###   ########.fr       */
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

t_index		add_index(t_index dest, t_index src)
{
	dest.x += src.x;
	dest.y += src.y;
	return (dest);
}

t_index		subtract_index(t_index dest, t_index src)
{
	dest.x -= src.x;
	dest.y -= src.y;
	return (dest);
}
