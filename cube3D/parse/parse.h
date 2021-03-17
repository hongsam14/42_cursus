/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:42:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:45:45 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../get_next_line/get_next_line.h"
# include "../base/base.h"
# include <fcntl.h>

typedef struct	s_world
{
	int			h;
	int			w;
	char		**map_data;
	t_tex		wall_tex[4];
	t_tex		sprite;
	int			f;
	int			c;
}				t_world;

int				open_cubfile(const char *file);
int				skip_empty_lines(int fd, char **line);
int				get_word(char *line, char ***content, int c);

int				get_info(t_world *world, t_window *win, char *file);

int				get_map(t_world *world, t_window *win, char *file);

#endif
