/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:52:07 by suhong            #+#    #+#             */
/*   Updated: 2021/03/28 01:08:44 by suhong           ###   ########.fr       */
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

void	init_data_struct(t_data *data);
void	parse(t_data *data, t_window *window, char *file);

void	load_world_init_data(t_data *data, t_game *game);
void	load_data_2_world(t_data *data, t_game *game);

int	save_bmp(t_game *game);

#endif
