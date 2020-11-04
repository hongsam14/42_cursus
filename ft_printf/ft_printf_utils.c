/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:48:02 by suhong            #+#    #+#             */
/*   Updated: 2020/11/04 13:17:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				del_t_format(t_format *f_start)
{
	t_format	*f_tmp;

	if (f_start == 0)
		return (0);
	while (f_start->next != 0)
	{
		f_tmp = f_start->next;
		free(f_start);
		f_start = f_tmp;
	}
	return (0);
}

int				add_t_format(t_format **f_info, t_format *start)
{
	t_format	*f_tmp;

	f_tmp = (t_format *)malloc(sizeof(t_format));
	if (f_tmp == 0)
		return (del_t_format(start));
	f_tmp->flag = 0;
	f_tmp->width = 0;
	f_tmp->decimal = 0;
	f_tmp->specifier = 0;
	f_tmp->next = 0;
	if (*f_info == 0)
	{
		*f_info = f_tmp;
		return (1);
	}
	while ((*f_info)->next != 0)
		*f_info = (*f_info)->next;
	(*f_info)->next = f_tmp;
	*f_info = (*f_info)->next;
	return (1);
}
