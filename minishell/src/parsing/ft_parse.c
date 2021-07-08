/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:00:11 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 04:16:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_put_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*new;
	char	*str;

	if (!built || !(built->command))
	{
		return ;
	}
	temp_l = built->command;
	while (temp_l)
	{
		if (temp_l->str && !ft_strncmp(temp_l->str, " ", 1) && temp_l->next && \
			!ft_strncmp(temp_l->next->str, " ", 1))
		{
			str = ft_strndup(" ", 1);
			new = ft_listnew(str, 0);
			ft_listadd_back(&temp_l, &new);
		}
		temp_l = temp_l->next;
	}
}
