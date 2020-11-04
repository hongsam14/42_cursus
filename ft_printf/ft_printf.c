/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/04 22:04:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_read_format.c"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*tmp;
	t_format	*f_info;

	tmp = (char *)format;
	f_info = 0;
	if (read_format(tmp, &f_info) < 1)
		return (0);
	va_start(lst, format);
	va_end(lst);
	del_t_format(&f_info);
	return (0);
}

int				main(void)
{
	ft_printf("abcd%0.4dabcd%cabcd, %-4d, %0d");
	return (0);
}
