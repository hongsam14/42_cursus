/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:34:13 by suhong            #+#    #+#             */
/*   Updated: 2021/03/22 22:08:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			search_map(t_data *data, t_index pos)
{
	int		i;
	char	*c;
	t_index	search;

	i = 0;
	c = get_map_node(data, pos);
	while (i < 8)
	{
		search = get_circle_index(pos, i);
		c = get_map_node(data, search);
		i++;
	}
}
