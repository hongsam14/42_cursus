/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:01:42 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 01:56:40 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		destroy_list(t_sprite **list)
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

static t_vec		get_transform(t_sprite *obj, t_game *game)
{
	t_vec		transform;
	t_vec		dir;
	t_vec		plane;
	double		i;

	plane = game->player.plane;
	dir = game->player.dir;
	i = 1 / (dir.y * plane.x - dir.x * plane.y);
	transform.x = i * (obj->pos.x * dir.y - obj->pos.y * dir.x);
	transform.y = i * (obj->pos.y * plane.x - obj->pos.x * plane.y);
	return (transform);
}

static void		get_index(t_vec tran, t_game *game, t_vec *start, t_vec *end)
{
	int		screen;
	int		width;

	screen = (int)(game->window.screen_w / 2) + (int)(tran.x / tran.y);
	width = (int)(game->window.screen_h / tran.y);
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

static t_vec		get_t_index(t_vec tran, t_game *game, t_vec start)
{
	t_vec		t_index;
	int		screen;
	int		width;

	screen = (int)(game->window.screen_w / 2) + (int)(tran.x / tran.y);
	width = (int)(game->window.screen_h / tran.y);
	t_index.x = start.x - screen + width / 2;
	t_index.y = start.y - game->window.screen_h / 2 + width / 2;
	t_index.x *= game->world.sprite.tex_w / width;
	t_index.y *= game->world.sprite.tex_h / width;
	return (t_index);
}

void			draw_sprites(t_sprite **list, t_ray *ray, t_game *game)
{
	t_vec		start;
	t_vec		end;
	t_vec		tran;
	t_vec		index;
	t_sprite	*obj;

	obj = *list;
	while (obj)
	{
		tran = get_transform(obj, game);
		get_index(tran, game, &start, &end);
		while (start.x <= end.x)
		{
			while (start.y <= end.y)
			{
				index = get_t_index(tran, game, start);
#if 0
				if (tran.y < ray[(int)start.x].dist)
				{
					game->window.img.data[(int)start.y
					* game->window.screen_w + (int)start.x]
					= game->world.sprite.img.data[(int)index.y
					* game->world.sprite.tex_w + (int)index.x];
					printf("print\n");
				}
#endif
				start.y++;
			}
			start.x++;
		}
		obj = obj->next;
	}
	destroy_list(list);
}
