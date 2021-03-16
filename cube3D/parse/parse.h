/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:42:33 by suhong            #+#    #+#             */
/*   Updated: 2021/03/16 22:02:01 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../engine/engine.h"

int	open_cubfile(const char *file);
int	skip_empty_lines(int fd, char **line);
int	get_map(t_world *world, char *file);

#endif
