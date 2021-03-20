/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:42:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 22:17:50 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../get_next_line/get_next_line.h"
# include "../base/base.h"
# include <fcntl.h>

# define SCREEN			1	
# define F_COLOR		2
# define C_COLOR		4
# define TEXTURE_WALL	8
# define TEXTURE_SPRITE	16

#if 1
typedef struct	s_world
{
	int				h;
	int				w;
	char			**map_data;
	t_tex			wall_tex[4];
	t_tex			sprite;
	int				f;
	int				c;
}					t_world;
#endif

typedef struct		s_row
{
	size_t			w_size;
	char			*content;
	struct s_row	*next;
}					t_row;

typedef struct		s_data
{
	int				f;
	int				c;
	int				screen_w;
	int				screen_h;
	char			*wall_tex[4];
	char			*sprite_tex;
	int				map_w;
	int				map_h;
	char			**map;
}					t_data;

int					open_cubfile(const char *file, int *fd);
int					skip_empty_lines(int fd, char **line);
int					get_word(char *line, char ***content, int c);
int					check_str(char *str, char *base);
int					get_rgb(char *str, int *color);

int					get_info(t_data *data, char *file);

int					make_square_map(int fd, int *w, int *h, char ***map);

int					get_map(t_world *world, t_window *win, char *file);

#endif
