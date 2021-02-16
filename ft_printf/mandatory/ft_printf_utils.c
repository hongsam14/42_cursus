/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:48:02 by suhong            #+#    #+#             */
/*   Updated: 2020/11/18 21:12:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				del_t_format(t_format **f_info)
{
	t_format	*f_tmp;

	if (*f_info == 0)
		return (-1);
	while (*f_info)
	{
		f_tmp = (*f_info)->next;
		free(*f_info);
		*f_info = f_tmp;
	}
	return (-1);
}

void			add_back_t_format(t_format **f_info, t_format *new_f)
{
	t_format	*f_tmp;

	if (*f_info == 0)
	{
		*f_info = new_f;
		return ;
	}
	f_tmp = *f_info;
	while (f_tmp->next)
		f_tmp = f_tmp->next;
	f_tmp->next = new_f;
}

int				init_t_format(t_format **new_f)
{
	*new_f = (t_format *)malloc(sizeof(t_format));
	if (*new_f == 0)
		return (-1);
	(*new_f)->flag = 0;
	(*new_f)->width = 0;
	(*new_f)->precision = 0;
	(*new_f)->specifier = 0;
	(*new_f)->next = 0;
	return (1);
}

char			change_2_hex(int value, int capital)
{
	char		output;

	if (capital)
		output = "0123456789ABCDEF"[value];
	else
		output = "0123456789abcdef"[value];
	return (output);
}

int				print_space_by_flag(t_format f_info)
{
	if ((f_info.flag & FLAG_ZERO))
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	return (1);
}
