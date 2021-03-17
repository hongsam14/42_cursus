/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:25:55 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:19:18 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../mlx_beta/mlx_beta.h"
# include "../libft/libft.h"

# define OK					0x00000001

# define ERROR_INIT_GAME	0xF1000000
# define ERROR_INIT_SIGHT	0xF2000000
# define ERROR_W_COLLISION	0xF0100000
# define ERROR_W_TEXTURE	0xF0200000
# define ERROR_S_CHECK_POOL	0xF0010000
# define ERROR_PARSING_FILE	0xF0001000

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*window;
}				t_mlx;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_tex
{
	t_img		img;
	int			tex_w;
	int			tex_h;
}				t_tex;

typedef struct	s_window
{
	t_mlx		mlx;
	t_img		img;
	int			screen_w;
	int			screen_h;
}				t_window;

int				init_window(t_window *window);
int				init_img(t_window *window);
int				destroy_window(t_window *window);
void			update_window(t_window *window);

int				load_texture(t_window *window, t_tex *tex, char *path);

int				rgb_color(int r, int g, int b);

t_vec			add_vector(t_vec dest, t_vec src);
t_vec			subtract_vector(t_vec dest, t_vec src);
t_vec			multiply_s_vector(t_vec dest, double src);

t_vec			get_vertical_vector(t_vec dest);
t_vec			get_floor_vector(t_vec dest);
double			get_vector_length(t_vec dest);

int				ft_debug(int code, t_window *window);
#endif
