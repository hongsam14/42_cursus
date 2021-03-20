/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:52:07 by suhong            #+#    #+#             */
/*   Updated: 2021/03/20 13:02:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "engine/engine.h"
# include "parse/parse.h"

void	init_game_struct(t_game *game);
int		init_engine(t_game *game);
void	draw_scene(t_game *game);
void	move_player(t_game *game);

int	load_screen_size_data(t_data *data, t_window *win);
int	load_text_from_data(t_data *data, t_world *world, t_window *win);
int	load_color_data(t_data *data, t_world *world);

#endif
