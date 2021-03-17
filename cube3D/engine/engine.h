/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 07:13:52 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 18:37:47 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../base/base.h"
# include "../controler/controler.h"
# include "../parse/parse.h"

# define INFO_NORTH	0xF000
# define INFO_SOUTH	0x0F00
# define INFO_WEST	0x00F0
# define INFO_EAST	0x000F

typedef struct		s_ray
{
	t_vec			ray;
	double			dist;
	int				info;
}					t_ray;

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
	t_vec			trans;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_sight
{
	t_ray			*ray;
	int				**pool;
	int				sprite_count;
}					t_sight;

typedef struct		s_game
{
	t_window		window;
	t_player		player;
	t_world			world;
	t_control		control;
	t_sight			sight;
}					t_game;

void				control_player(t_game *game);

t_vec				get_delta_dist(t_vec ray);
t_vec				get_side_dist(t_vec ray, t_vec pos, t_vec d_dist
		, t_vec *map);
void				move_by_dda(t_vec *map, t_vec *s_dist, t_vec d_dist
		, t_ray *ray);

void				init_pool(int **pool, t_world world);
void				update_pool(int **pool, t_ray *ray, t_vec pos
		, t_world world);

int					check_pool(int **pool, t_game game, t_sprite **list);

void				draw_sprites(t_sprite **list, t_game *game);

double				wall_collision(t_ray *ray, t_vec pos, t_world world);

int					get_color(int color, double dist, int info);

int					init_sight(t_game *game);
void				raycasting(t_game *game);

int					draw_wall(t_game *game, t_ray *ray, int r_index);
void				draw_sky_ground(t_window *window, int sky, int ground);

void				collider(t_game *game);

#endif
