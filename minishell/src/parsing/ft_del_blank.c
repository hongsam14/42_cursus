/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:08:30 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 04:16:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	t_list	*ft_find_head(t_list *list)
{
	t_list	*temp;

	if (!list)
		return (ft_listnew(ft_strndup("", 0), 0));
	temp = list;
	while (temp && temp->prev)
		temp = temp->prev;
	return (temp);
}

void	ft_del_lastblank(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;
	t_list	*head;

	if (!built || !built->command)
		return ;
	head = 0;
	temp_l = built->command;
	head = 0;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strncmp(temp_l->str, " ", 1) && !(temp_l->next))
		{
			ft_listdelone(&temp_l);
			break ;
		}
		else
			head = temp_l;
		temp_l = temp_l2;
	}
	built->command = ft_find_head(head);
}

void	ft_del_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;
	t_list	*head;

	if (!built)
		return ;
	temp_l = built->command;
	head = 0;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (!(temp_l->str) || (temp_l->str && ft_strlen(temp_l->str) == 0))
			ft_listdelone(&temp_l);
		else
			head = temp_l;
		temp_l = temp_l2;
	}
	built->command = ft_find_head(head);
}

void	ft_del_blank2(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	if (!built)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strncmp(temp_l->str, " ", 1))
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}
