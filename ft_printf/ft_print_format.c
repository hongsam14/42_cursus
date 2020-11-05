/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:34:52 by suhong            #+#    #+#             */
/*   Updated: 2020/11/05 21:08:39 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_by_specifier(va_list *v_lst, t_format f_info)
{
	char	specifier;

	specifier = f_info.specifier;
	if (specifier == 'c')
		return (read_c_type(va_arg(*v_lst, char), f_info));
	if (specifier == 'p')
		return (read_p_type(va_arg(*v_lst, long long), f_info));
	if (specifier == 's')
		return (read_s_type(va_arg(*v_lst, char *), f_info));
	if (specifier == 'd' || specifier == 'i')
		return (read_di_type(va_arg(*v_lst, int), f_info));
	if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		return (read_uxX_type(va_arg(*v_lst, unsigned int), f_info));
}

int			print_format(char *format, t_format f_info, va_list v_lst)
{
	char	*tmp;
	int		read_byte;

	tmp = format;
	read_byte = 0;
	while (*tmp != '\0')
	{
		while (*tmp != '%')
		{
			write(1, tmp++, 1);
			read_byte++;
		}
		read_byte += print_by_specifier(v_lst, f_info);
		while ((ft_strchr("cspdiuxX", *tmp)) == 0)
		{
			tmp++;
		}
		tmp++;
		read_byte += print_by_specifier(*v_lst, f_info);
	}
	return (read_byte);
}
