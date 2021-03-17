/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:12:30 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 17:45:46 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_sprite	*init_list(int x, int y, t_player player)
{
	t_sprite	*add;
	t_vec		dir;
	t_vec		plane;
	double		i;

	add = (t_sprite *)malloc(sizeof(t_sprite));
	if (!add)
		return (0);
	add->pos.x = x + 0.5 - player.pos.x;
	add->pos.y = y + 0.5 - player.pos.y;
	plane = player.plane;
	dir = player.dir;
	i = 1 / (dir.y * plane.x - plane.y * dir.x);
	add->trans.x = i * (add->pos.x * dir.y - add->pos.y * dir.x);
	add->trans.y = i * (add->pos.y * plane.x - add->pos.x * plane.y);
	add->next = 0;
	return (add);
}

static int		add_list(int x, int y, t_player player, t_sprite **lst)
{
	t_sprite	*add;
	t_sprite	*tmp;
	t_sprite	*i;

	add = init_list(x, y, player);
	if (!add)
		return (0);
	if (*lst == 0)
	{
		*lst = add;
		return (1);
	}
	i = *lst;
	tmp = 0;
	while (i && add->trans.y < i->trans.y)
	{
		tmp = i;
		i = i->next;
	}
	if (!tmp)
		*lst = add;
	else
		tmp->next = add;
	add->next = i;
	return (1);
}

int				check_pool(int **pool, t_game game, t_sprite **lst)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < game.world.h)
	{
		x = 0;
		while (x < game.world.w)
		{
			if (pool[y][x] == 1)
			{
				if (!add_list(x, y, game.player, lst))
					return (ft_debug(ERROR_S_CHECK_POOL, &game.window));
			}
			x++;
		}
		y++;
	}
	return (ft_debug(OK, &game.window));
}
