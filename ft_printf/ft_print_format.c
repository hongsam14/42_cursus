/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:34:52 by suhong            #+#    #+#             */
/*   Updated: 2020/11/08 18:42:55 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "read_c_type.c"
#include "read_s_type.c"
#include "read_percent_type.c"

static int	print_by_specifier(va_list *v_lst, t_format f_info)
{
	char	specifier;

	specifier = f_info.specifier;
	if (specifier == 'c')
		return (read_c_type(va_arg(*v_lst, int), f_info));
	if (specifier == 's')
		return (read_s_type(va_arg(*v_lst, char *), f_info));
	/*
	if (specifier == 'p')
		return (read_p_type(va_arg(*v_lst, long long), f_info));
	if (specifier == 'd' || specifier == 'i')
		return (read_di_type(va_arg(*v_lst, int), f_info));
	if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		return (read_uxX_type(va_arg(*v_lst, unsigned int), f_info));
	*/
	if (specifier == '%')
		return (read_percent_type(f_info));
	return (0);
}

int			print_format(char *format, t_format *f_info, va_list *v_lst)
{
	int		read_byte;

	read_byte = 0;
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			write(1, format++, 1);
			read_byte++;
		}
		if (*format == '%' && *format != '\0')
		{
			format++;
			while ((ft_strchr("-*.0123456789", *format)) != 0
					&& *format != '\0')
				format++;
			while ((ft_strchr("%", *format)) != 0 && *format != '\0')
				format++;
			while ((ft_strchr("cpsdiuxX", *format)) != 0 && *format != '\0')
				format++;
			read_byte += print_by_specifier(v_lst, *f_info);
			f_info = f_info->next;
		}
	}
	return (read_byte);
}
