/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:52:07 by suhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:46:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "engine/engine.h"

void	init_game_struct(t_game *game);
int		init_engine(t_game *game);
void	draw_scene(t_game *game);
void	move_player(t_game *game);

#endif
