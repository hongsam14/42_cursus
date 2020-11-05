/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/05 20:50:14 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_read_format.c"
#include <stdio.h>

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*tmp;
	t_format	*f_info;

	tmp = (char *)format;
	f_info = 0;
	va_start(lst, format);
	if (read_format(tmp, &f_info, &lst) < 1)
		return (0);
	printf("%s\n", va_arg(lst, char *));
	va_end(lst);
	del_t_format(&f_info);
	return (1);
}

int				main(void)
{
	printf("%d", ft_printf("abcd%0*.*dabcd%10cabcd, %-4d, %0d", 10, 5, "abcd"));
	return (0);
}
