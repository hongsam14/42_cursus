/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:42:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/23 18:47:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../get_next_line/get_next_line.h"
# include "../base/base.h"
# include <fcntl.h>

# define SCREEN			0X00000001
# define F_COLOR		0X00000010
# define C_COLOR		0X00000100
# define TEXTURE_SPRITE	0X00001000
# define TEXTURE_WALL	0X11110000

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
	t_index			player_pos;
	char			player_dir;
}					t_data;

int					open_cubfile(const char *file, int *fd);
int					skip_empty_lines(int fd, char **line);
int					get_word(char *line, char ***content, int c);
int					check_str(char *str, char *base);
int					get_rgb(char *str, int *color);

int					get_info(t_data *data, char *file);

int					make_square_map(int fd, int *w, int *h, char ***map);

char				*get_map_node(t_data *data, t_index pos);
t_index				get_circle_index(t_index pos, int i);

int					judge_map(t_data *data);

#endif
