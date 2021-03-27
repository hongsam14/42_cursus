/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:47:36 by suhong            #+#    #+#             */
/*   Updated: 2021/03/28 01:44:56 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		write_little_endian(unsigned char *dest, int value)
{
	size_t		size;
	int		i;

	i = 0;
	size = sizeof(int);
	while (i < size)
	{
		dest[i] = (value >> (8 * i));
		i++;
	}
}

static int		write_file_header(int fd, int file_size)
{
	unsigned char	tmp[14];
	int		i;
	
	i = 0;
	while (i < 14)
		tmp[i++] = (unsigned char)(0);
	tmp[0] = (unsigned char)('B');
	tmp[1] = (unsigned char)('M');
	write_little_endian(&tmp[2], file_size);
	write_little_endian(&tmp[10], 54);
	return (write(fd, tmp, 14));
}

static int		write_info_header(int fd, int w, int h)
{
	unsigned char	tmp[40];
	int		i;
	
	i = 0;
	while (i < 40)
		tmp[i++] = (unsigned char) 0;
	write_little_endian(&tmp[0], 40);
	write_little_endian(&tmp[4], w);
	write_little_endian(&tmp[8], h);
	tmp[12] = (unsigned char)(1);
	tmp[14] = (unsigned char)(24);
	return (write(fd, tmp, 40));
}

static int		get_pixel_data(t_window win, int x, int y)
{
	int		color;
	int		size_x;
	int		size_y;

	size_x = win.screen_w;
	size_y = win.screen_h;
	color = win.img.data[x + (size_y - 1 - y) * size_x];
	return (color & 0xFFFFFF);
}

static int		write_bmp_data(int fd, t_window win, int pad)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < win.screen_h)
	{
		j = 0;
		while (j < win.screen_w)
		{
			color = get_pixel_data(win, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			j++;
		}
		if (pad > 0 && write(fd, "000", pad) < 0)
			return (0);
		i++;
	}
	return (1);
}

int			save_bmp(t_game *game)
{
	int		fd;
	int		pad;
	int		size;

	pad = (4 - (game->window.screen_w * 3) % 4) % 4;
	size = ((game->window.screen_w + pad) * 3 *  game->window.screen_h) + 54;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (0);
	if (write_file_header(fd, size) < 0)
		return (0);
	if (write_info_header(fd, game->window.screen_w, game->window.screen_h) < 0)
		return (0);
	if (!write_bmp_data(fd, game->window, pad))
		return (0);
	close(fd);
	return (1);
}
