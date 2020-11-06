/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/06 18:47:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_read_format.c"
#include "ft_print_format.c"
#include <stdio.h>

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*tmp;
	t_format	*f_info;
	int			read_byte;

	tmp = (char *)format;
	f_info = 0;
	read_byte = 0;
	va_start(lst, format);
	if (read_format(tmp, &f_info, &lst) < 1)
		return (0);
	if ((read_byte = print_format(tmp, f_info, &lst)) < 1)
		return (0);
	va_end(lst);
	del_t_format(&f_info);
	return (read_byte);
}

int				main(void)
{
	ft_printf("abcd%0*.*dabcd%10sabcd, %-4d, %%", 10, 5, 10, "ABCD", 10);
	return (0);
}
