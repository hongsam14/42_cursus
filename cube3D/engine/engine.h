/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:13:52 by suhong            #+#    #+#             */
/*   Updated: 2021/03/03 20:51:17 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../base/base.h"
# include "../controler/controler.h"

# define INFO_NORTH	0xF000
# define INFO_SOUTH	0x0F00
# define INFO_WEST	0x00F0
# define INFO_EAST	0x000F

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*window;
}					t_mlx;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_ray
{
	t_vec			ray;
	double			dist;
	int				info;
}					t_ray;

typedef struct		s_tex
{
	t_img			img;
	int				tex_w;
	int				tex_h;
}					t_tex;

typedef struct		s_window
{
	t_mlx			mlx;
	t_img			img;
	int				screen_w;
	int				screen_h;
}					t_window;

typedef struct		s_player
{
	t_vec			pos;
	t_vec			plane;
	t_vec			dir;
	t_vec			old_pos;
}					t_player;

typedef struct		s_sprite
{
	t_vec			pos;
	double			dist;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_world
{
	int				rows;
	int				cols;
	int				*map_data;
	t_tex			wall_tex[4];
	t_tex			sprite_tex;
}					t_world;

typedef struct		s_game
{
	t_window		window;
	t_player		player;
	t_world			world;
	t_control		control;
}					t_game;

int					init_window(t_window *window);
int					init_img(t_window *window);
int					destroy_window(t_window *window);
void				update_window(t_window *window);

int					load_texture(t_window *window, t_tex *tex, char *path);

void				move_player_fb(t_player *player, int dir, double speed);
void				move_player_lr(t_player *player, int dir, double speed);
void				turn_player_lr(t_player *player, int dir, double speed);

t_vec				get_delta_dist(t_vec ray);
t_vec				get_side_dist(t_vec ray, t_vec pos, t_vec d_dist
		, t_vec *map);
void				move_by_dda(t_vec *map, t_vec *s_dist, t_vec d_dist
		, t_ray *ray);

double				wall_collision(t_ray *ray, t_vec pos, t_world world
		, int obj);
int					sprite_collision(t_ray *ray, t_vec pos, t_world world
		, t_sprite *list);

int					raycasting(t_game *game);

int					draw_wall(t_game *game, t_ray *ray, int r_index);
void				draw_sky_ground(t_window *window, int sky, int ground);

void				collider(t_game *game);

#endif
