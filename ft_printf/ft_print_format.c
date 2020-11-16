/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:34:52 by suhong            #+#    #+#             */
/*   Updated: 2020/11/16 12:45:01 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_by_specifier(va_list *v_lst, t_format f_info)
{
	char	specifier;

	specifier = f_info.specifier;
	if (specifier == 'c')
		return (read_c_type(va_arg(*v_lst, int), f_info));
	if (specifier == 's')
		return (read_s_type(va_arg(*v_lst, char *), f_info));
	if (specifier == 'p')
		return (read_p_type(va_arg(*v_lst, void *), f_info));
	if (specifier == 'd' || specifier == 'i')
		return (read_di_type(va_arg(*v_lst, int), f_info));
	if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		return (read_ux_type(va_arg(*v_lst, unsigned int), f_info));
	if (specifier == '%')
		return (read_percent_type(f_info));
	return (-1);
}

void		jump_flag(char **format)
{
	char	*tmp;

	tmp = *format;
	while ((ft_strchr("-*.0123456789", *tmp)) != 0
			&& *tmp != '\0')
		tmp++;
	while ((ft_strchr("%", *tmp)) != 0 && *tmp != '\0')
		tmp++;
	while ((ft_strchr("cpsdiuxX", *tmp)) != 0 && *tmp != '\0')
		tmp++;
	*format = tmp;
}

int			print_format(char *format, t_format *f_info, va_list *v_lst)
{
	int		read_byte;
	int		spec_byte;

	read_byte = 0;
	spec_byte = 0;
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
			jump_flag(&format);
			if ((spec_byte = print_by_specifier(v_lst, *f_info)) < 0)
				return (-1);
			read_byte += spec_byte;
			f_info = f_info->next;
		}
	}
	return (read_byte);
}
