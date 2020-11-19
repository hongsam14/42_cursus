/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/19 15:04:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*tmp;
	t_format	*f_info;
	int			read_byte;

	if (!format)
		return (-1);
	tmp = (char *)format;
	f_info = 0;
	read_byte = 0;
	va_start(lst, format);
	if (read_format(tmp, &f_info, &lst) < 0)
	{
		va_end(lst);
		return (-1);
	}
	read_byte = print_format(tmp, f_info);
	va_end(lst);
	del_t_format(&f_info);
	return (read_byte);
}
