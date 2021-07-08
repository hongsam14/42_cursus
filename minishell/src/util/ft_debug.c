/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:42:39 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 04:16:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	test_print_parsing(t_built *built)
{
	t_list	*temp_l;

	temp_l = built->command;
	write(2, "          parsing print : ", 26);
	while (temp_l)
	{
		write(2, "[", 1);
		ft_putstr_fd(temp_l->str, 2, 0);
		write(2, "]", 1);
		temp_l = temp_l->next;
	}
	write(2, "\n", 1);
}

void	test_built_list(t_built *built)
{
	t_built	*tmp;

	tmp = built;
	while (tmp)
	{
		test_print_parsing(tmp);
		write(2, "\n", 1);
		tmp = tmp->next;
	}
}

void	test_print_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	if (temp->prev)
		temp->prev->next = 0;
	while (temp)
	{
		write(2, "[", 1);
		ft_putstr_fd(temp->str, 2, 0);
		write(2, "]\n", 2);
		temp = temp->next;
	}
}
