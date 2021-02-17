/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:13:52 by suhong            #+#    #+#             */
/*   Updated: 2021/02/17 11:59:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "vector.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*window;
}		t_mlx;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}		t_img;

typedef struct s_window
{
	t_mlx		mlx;
	t_img		img;
	int			screen_w;
	int			screen_h;
}		t_window;

typedef struct s_player
{
	t_vec		pos;
	t_vec		plane;
	t_vec		dir;
}		t_player;

typedef struct s_world
{
	int			rows;
	int			cols;
	int			*map_data;
}		t_world;

typedef struct s_game
{
	t_window	window;
	t_player	player;
	t_world		world;
}		t_game;

int		init_window(t_window *window);
int		init_img(t_window *window);
int		destroy_window(t_window *window);
void	update_window(t_window *window);

void	move_player_fb(t_player *player, int dir, double speed);
void	move_player_lr(t_player *player, int dir, double speed);
void	turn_player_lr(t_player *player, int dir, double speed);

int		raycasting(t_game *game);

void	draw_sky_ground(t_window *window, int sky, int ground);
void	draw_col(t_window *window, double dist, int r_index, int hor);

#endif
