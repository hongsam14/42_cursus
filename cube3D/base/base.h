/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:25:55 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 21:29:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct	s_vec
{
	double	x;
	double	y;
}		t_vec;

t_vec		add_vector(t_vec dest, t_vec src);
t_vec		multiply_s_vector(t_vec dest, double src);
t_vec		get_vertical_vector(t_vec dest);
t_vec		get_floor_vector(t_vec dest);

# endif
