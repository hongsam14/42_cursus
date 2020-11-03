/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/03 00:54:32 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_read_format.c"

static int		print_format(char *format, va_list lst)
{
	char		*tmp;

	while (*tmp != '%' || *tmp != '\0')
		write (1, tmp++, 1);
}

int			ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*tmp;
	t_format	f_info;

	tmp = (char *)format;
	f_info.flag = 0;
	f_info.width = 0;
	f_info.decimal = 0;
	f_info.specifier = 0;
	f_info.next = 0;
	if (read_format(tmp, &f_info) < 1)
		return (0);
	va_start(lst, format);
	while (*tmp != '\0')
	{
		print_format(&tmp, lst);
	}
	va_end(lst);
	return (0);
}

int		main(void)
{
	ft_printf("abcd%0+ 10dabcd", 12);
	return (0);
}
