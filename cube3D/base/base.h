/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:25:55 by suhong            #+#    #+#             */
/*   Updated: 2021/03/06 16:06:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define OK					0x00000001

# define ERROR_INIT_GAME	0xF1000000
# define ERROR_INIT_SIGHT	0xF2000000
# define ERROR_W_COLLISION	0xF0100000
# define ERROR_W_TEXTURE	0xF0200000
# define ERROR_S_CHECK_POOL	0xF0010000

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

t_vec			add_vector(t_vec dest, t_vec src);
t_vec			subtract_vector(t_vec dest, t_vec src);
t_vec			multiply_s_vector(t_vec dest, double src);

t_vec			get_vertical_vector(t_vec dest);
t_vec			get_floor_vector(t_vec dest);
double			get_vector_length(t_vec dest);

int				ft_debug(int code);

# endif
