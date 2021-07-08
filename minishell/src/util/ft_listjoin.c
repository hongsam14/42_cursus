/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:38:13 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 23:01:26 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_list	*ft_list_join(t_list *first, t_list *second)
{
	char	*new_str;
	t_list	*new_list;

	if (!ft_malloc(&new_list, sizeof(t_list)))
		return (NULLPTR);
	new_str = ft_strjoin(first->str, second->str);
	ft_free(first->str);
	ft_free(second->str);
	new_list->str = new_str;
	new_list->next = second->next;
	new_list->prev = first->prev;
	if (first->prev)
		first->prev->next = new_list;
	if (second->next)
		second->next->prev = new_list;
	ft_free(first);
	ft_free(second);
	return (new_list);
}

int	ft_listjoin(t_built *built)
{
	t_list	*temp_l;

	temp_l = built->command;
	while (temp_l)
	{
		if (*(temp_l->str) != ' ' && temp_l->next \
				&& *(temp_l->next->str) != ' ')
			temp_l = ft_list_join(temp_l, temp_l->next);
		else
			temp_l = temp_l->next;
	}
	return (1);
}
