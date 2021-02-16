#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ROWS	10
#define COLS	10

#define TILE_SIZE	32

#define SCREEN_W	COLS * TILE_SIZE
#define SCREEN_H	ROWS * TILE_SIZE

#define EVENT_KEYPRESS	2
#define EVENT_EXIT	17

#define KEY_ESC		53

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

typedef struct	s_game
{
	t_mlx	mlx;
	t_img	img;
	int	map[ROWS][COLS];
}		t_game;

void		init_img(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx.mlx_ptr, SCREEN_W, SCREEN_H);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

void		init_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx_ptr, SCREEN_W, SCREEN_H, "practice");
}

void		game_init(t_game *game)
{
	int	map[ROWS][COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	ft_memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

int		press_ESC(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
	}
	return (0);
}

int		press_red_cross(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(0);
	return (0);
}

#if 0

void		draw_line(t_game *game, double x1, double y1, double x2, double y2)
{

}

#else

void		draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	xinc;
	double	yinc;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY);
	xinc = deltaX / step;
	yinc = deltaY / step;
	while (step--)
	{
		game->img.data[(int)round(y1) * SCREEN_W + (int)round(x1)] = 0xb3b3b3;
		x1 += xinc;
		y1 += yinc;
	}
}

#endif

void		draw_guid_lines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0 , i * TILE_SIZE, SCREEN_H);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0 , COLS * TILE_SIZE - 1, SCREEN_H);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, SCREEN_W, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, SCREEN_W, ROWS * TILE_SIZE - 1);
}

int		main(int argc, char *argv[])
{
	t_game	game;

	init_window(&game);
	init_img(&game);
	draw_guid_lines(&game);
	//draw_line(&game, 1 * TILE_SIZE, 1 * TILE_SIZE, 3 * TILE_SIZE, 3 * TILE_SIZE);
	draw_line(&game, ft_atoi(argv[1]) * TILE_SIZE, ft_atoi(argv[2]) * TILE_SIZE, ft_atoi(argv[3]) * TILE_SIZE, ft_atoi(argv[4]) * TILE_SIZE);
	mlx_put_image_to_window(game.mlx.mlx_ptr, game.mlx.window, game.img.img_ptr, 0, 0);
	mlx_hook(game.mlx.window, EVENT_KEYPRESS, 1l<<0, &press_ESC, &game.mlx);
	mlx_hook(game.mlx.window, EVENT_EXIT, 1l<<17, &press_red_cross, &game.mlx);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
