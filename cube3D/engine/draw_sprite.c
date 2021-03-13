/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:01:42 by suhong            #+#    #+#             */
/*   Updated: 2021/03/13 13:56:03 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void		destroy_list(t_sprite **list)
{
	t_sprite	*tmp;

	if (*list == 0)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

static void		get_index(t_vec tran, t_game *game, t_vec *start, t_vec *end)
{
	int			screen;
	int			width;

	screen = (int)((game->window.screen_w / 2) * (1 + tran.x / tran.y));
	width = abs((int)(game->window.screen_h / tran.y));
	start->x = screen - width / 2;
	start->y = game->window.screen_h / 2 - width / 2;
	end->x = screen + width / 2;
	end->y = game->window.screen_h / 2 + width / 2;
	if (start->x < 0)
		start->x = 0;
	if ((int)end->x >= game->window.screen_w)
		end->x = game->window.screen_w - 1;
	if (start->y < 0)
		start->y = 0;
	if ((int)end->y >= game->window.screen_h)
		end->y = game->window.screen_h - 1;
}

static t_vec	get_t_index(t_vec tran, t_game *game, t_vec start)
{
	t_vec		t_index;
	int			screen;
	int			width;

	screen = (int)((game->window.screen_w / 2) * (1 + tran.x / tran.y));
	width = abs((int)(game->window.screen_h / tran.y));
	t_index.x = start.x - screen + width / 2;
	t_index.y = start.y - game->window.screen_h / 2 + width / 2;
	t_index.x *= 1.0 * game->world.sprite.tex_w / width;
	t_index.y *= 1.0 * game->world.sprite.tex_h / width;
	if ((int)t_index.y >= game->world.sprite.tex_h)
		t_index.y = game->world.sprite.tex_h - 1;
	if ((int)t_index.x >= game->world.sprite.tex_w)
		t_index.x = game->world.sprite.tex_w - 1;
	return (t_index);
}

static void		get_tex_data(t_game *game, t_vec s, t_vec i, t_sprite obj)
{
	int			screen_w;
	int			tex_w;
	int			*s_data;
	int			*t_data;
	int			color;

	screen_w = game->window.screen_w;
	tex_w = game->world.sprite.tex_w;
	s_data = game->window.img.data;
	t_data = game->world.sprite.img.data;
	if (obj.trans.y < game->sight.ray[(int)s.x].dist)
	{
		color = t_data[(int)i.y * tex_w + (int)i.x];
		if ((color & ~(0xFF << 24)) != 0)
			s_data[(int)s.y * screen_w + (int)s.x] =
				get_color(color, obj.trans.y, 0);
	}
}

void			draw_sprites(t_sprite **list, t_game *game)
{
	t_vec		start;
	t_vec		end;
	t_vec		index;
	t_sprite	*obj;
	double		y;

	obj = *list;
	while (obj)
	{
		get_index(obj->trans, game, &start, &end);
		y = start.y;
		while ((int)start.x <= (int)end.x)
		{
			start.y = y;
			while ((int)start.y <= (int)end.y)
			{
				index = get_t_index(obj->trans, game, start);
				get_tex_data(game, start, index, *obj);
				start.y++;
			}
			start.x++;
		}
		obj = obj->next;
	}
	destroy_list(list);
}
