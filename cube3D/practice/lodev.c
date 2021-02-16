#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../mlx_beta/mlx.h"
#include "../libft/libft.h"

#define	SCREEN_WIDTH	800
#define	SCREEN_HEIGHT	600

#define	ROWS		20
#define	COLS		20

#define EVENT_KEYPRESS	2
#define EVENT_EXIT	17

#define	KEY_ESC		53
#define KEY_W		13
#define KEY_S		1
#define KEY_A		0
#define KEY_D		2
#define KEY_LEFT	123
#define KEY_RIGHT	124

typedef struct	s_vec
{
	double	x;
	double	y;
}		t_vec;

t_vec		vector_add(t_vec dest, t_vec add)
{
	dest.x += add.x;
	dest.y += add.y;
	return (dest);
}

t_vec		vector_s_multiply(t_vec dest, double mul)
{
	dest.x *= mul;
	dest.y *= mul;
	return (dest);
}

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*window;
}		t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	int	*data;
	int	size_l;
	int	bpp;
	int	endian;
}		t_img;

//player_pos : 플레이어 위치벡터, dir_vec : 플레이어 방향벡터, plane_vec : 시야각 벡터
typedef struct	s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
}		t_player;

typedef struct	s_game
{
	t_mlx		mlx;
	t_img		img;
	t_player	player;
	int		map[ROWS][COLS];
}			t_game;

void		clear_image(int *img_data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		img_data[i] = 0;
		i++;
	}
}

double		getWallDist(t_vec ray_vec, t_game *game, int *side)
{
	t_vec	deltaDist;
	t_vec	sideDist;
	t_vec	perpDist;
	
	int	map_x;
	int	map_y;
	
	int	step_x;
	int	step_y;

	double	dist;
	
	deltaDist.x = fabs(1 / ray_vec.x);
	deltaDist.y = fabs(1 / ray_vec.y);
	map_x = (int)game->player.pos.x;
	map_y = (int)game->player.pos.y;
	if (ray_vec.x < 0)
	{
		step_x = -1;
		sideDist.x = (game->player.pos.x - map_x) * deltaDist.x;
	}
	else
	{
		step_x = 1;
		sideDist.x = (map_x + 1 - game->player.pos.x) * deltaDist.x;
	}
	if (ray_vec.y < 0)
	{
		step_y = -1;
		sideDist.y = (game->player.pos.y - map_y) * deltaDist.y;
	}
	else
	{
		step_y = 1;
		sideDist.y = (map_y + 1 - game->player.pos.y) * deltaDist.y;
	}
	perpDist = sideDist;
#if 1
	//perform DDA
	while (1)
	{
		if (perpDist.x < perpDist.y)
		{
			map_x += step_x;
			*side = 0;
			if (game->map[map_y][map_x] > 0)
			{
				//세로선에 충돌
				dist = perpDist.x;
				break ;
			}
			else
			{
				perpDist.x += deltaDist.x;
			}
		}
		else
		{
			map_y += step_y;
			*side = 1;
			if (game->map[map_y][map_x] > 0)
			{
				//가로선에 충돌
				dist = perpDist.y;
				break ;
			}
			else
			{
				perpDist.y += deltaDist.y;
			}
		}
	}
#else
	while (1)
	{
		if (perpDist.x < perpDist.y)
		{
			map_x += step_x;
			*side = 0;
			perpDist.x += deltaDist.x;
		}
		else
		{
			map_y += step_y;
			*side = 1;
			perpDist.y += deltaDist.y;
		}
		if (game->map[map_y][map_x] > 0)
		{
			break;
		}
	}
	if (*side == 0)
	{
		dist = (map_x - game->player.pos.x + (1 - step_x) / 2) / ray_vec.x;
	}
	else
	{
		dist = (map_y - game->player.pos.y + (1 - step_y) / 2) / ray_vec.y;
	}
#endif
	return (dist);
}

void		draw_line_in_screen(int x_count, int side, t_vec ray, double perpDist, t_game *game)
{
	int	lineHeight;
	int	line_start;
	int	line_end;

	lineHeight = (int)(SCREEN_HEIGHT / perpDist);
	line_start = (SCREEN_HEIGHT / 2) - (lineHeight / 2);
	line_start = line_start < 0 ? 0 : line_start;
	line_end = (SCREEN_HEIGHT / 2) + (lineHeight / 2);
	line_end = line_end > SCREEN_HEIGHT ? SCREEN_HEIGHT - 1 : line_end;
	while (line_start <= line_end)
	{
		if (side == 0)
		{
			if (ray.x < 0)
			{
				//east
				game->img.data[line_start * SCREEN_WIDTH + x_count] = 0xFFFFFF;
			}
			else
			{
				//west
				game->img.data[line_start * SCREEN_WIDTH + x_count] = 0xFFFFFF;
			}
		}
		else
		{
			if (ray.y < 0)
			{
				//north
				game->img.data[line_start * SCREEN_WIDTH + x_count] = 0x888888;
			}
			else
			{
				//south
				game->img.data[line_start * SCREEN_WIDTH + x_count] = 0x888888;
			}
		}
		line_start++;
	}
}

int		raycasting(t_game *game)
{
	//screen_x : 픽셀의 위치 벡터의 x값
	int	x_count;
	int	side;
	double	screen_x;
	double	perpDist;
	//ray_vec : 광선의 벡터
	t_vec	ray_vec;
	t_vec	plane;
	
	x_count = 0;
	side = 0;
	//mlx_clear_window(game->mlx.mlx_ptr, game->mlx.window);
	clear_image(game->img.data, SCREEN_HEIGHT * SCREEN_WIDTH);
	while (x_count < SCREEN_WIDTH)
	{
		screen_x = (x_count * 2 / (double)SCREEN_WIDTH) - 1;
		plane = vector_s_multiply(game->player.plane, screen_x);
		ray_vec = vector_add(game->player.dir, plane);
		
		perpDist = getWallDist(ray_vec, game, &side);
		draw_line_in_screen(x_count, side, ray_vec, perpDist, game);
		
		x_count++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.window, game->img.img_ptr, 0, 0);
	return (0);
}

void			rotate_player_dir(t_player *player, int left)
{
	double		angle;
	double		x;
	double		y;

	angle = 0.1;
	angle *= left;
	x = player->dir.x;
	y = player->dir.y;
	player->dir.x = x * cos(angle) - y * sin(angle);
	player->dir.y = x * sin(angle) + y * cos(angle);
	player->plane.x = player->dir.y;
	player->plane.y = -player->dir.x;
}

void			move_player_pos_front(t_player *player, int front)
{
	t_vec		dir_len;

	dir_len = vector_s_multiply(player->dir, 0.1 * front);
	player->pos = vector_add(player->pos, dir_len);
}

void			move_player_pos_side(t_player *player, int right)
{
	t_vec		plane_len;

	plane_len = vector_s_multiply(player->plane, 0.1 * right);
	player->pos = vector_add(player->pos, plane_len);
}

int			keypress(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		move_player_pos_front(player, 1);
	if (keycode == KEY_S)
		move_player_pos_front(player, -1);;
	if (keycode == KEY_A)
		move_player_pos_side(player, -1);
	if (keycode == KEY_D)
		move_player_pos_side(player, 1);
	if (keycode == KEY_LEFT)
		rotate_player_dir(player, 1);
	if (keycode == KEY_RIGHT)
		rotate_player_dir(player, -1);
	return (0);
}

int			red_cross(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(0);
	return (0);
}

int			main(void)
{
	t_game		game;
	
	int		map[ROWS][COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
	};

	game.player.pos.x = 5;
	game.player.pos.y = 5;
	game.player.dir.x = 0;
	game.player.dir.y = -0.7;
	game.player.plane.x = 1;
	game.player.plane.y = 0;
	
	ft_memcpy(game.map , map, sizeof(int) * ROWS * COLS);
	game.mlx.mlx_ptr = mlx_init();
	game.mlx.window = mlx_new_window(game.mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "practice");
	game.img.img_ptr = mlx_new_image(game.mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	game.img.data = (int *)mlx_get_data_addr(game.img.img_ptr, &game.img.bpp, &game.img.size_l, &game.img.endian);
	mlx_hook(game.mlx.window, EVENT_KEYPRESS, 1L<<0, &keypress, &game.player);
	mlx_hook(game.mlx.window, EVENT_EXIT, 1L<<17, &red_cross, &game.mlx);
	mlx_loop_hook(game.mlx.mlx_ptr, &raycasting, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
