/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:34:52 by suhong            #+#    #+#             */
/*   Updated: 2020/11/19 21:00:16 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_by_specifier(t_format f_info)
{
	char	specifier;

	specifier = f_info.specifier;
	if (specifier == 'c')
		return (read_c_type((int)(f_info.content), f_info));
	if (specifier == 's')
		return (read_s_type((char *)(f_info.content), f_info));
	if (specifier == 'p')
		return (read_p_type((void *)(f_info.content), f_info));
	if (specifier == 'd' || specifier == 'i')
		return (read_di_type((int)(f_info.content), f_info));
	if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		return (read_ux_type((unsigned int)f_info.content, f_info));
	if (specifier == '%')
		return (read_percent_type(f_info));
	return (-1);
}

static void	jump_flag(char **format)
{
	char	*tmp;

	tmp = *format;
	while ((ft_strchr("-*# +.0123456789", *tmp)) != 0
			&& *tmp != '\0')
		tmp++;
	if ((ft_strchr("cpsdiuxX%", *tmp)) != 0 && *tmp != '\0')
		tmp++;
	*format = tmp;
}

int			print_format(char *format, t_format *f_info)
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
			if ((spec_byte = print_by_specifier(*f_info)) < 0)
				return (-1);
			read_byte += spec_byte;
			f_info = f_info->next;
		}
	}
	return (read_byte);
}
