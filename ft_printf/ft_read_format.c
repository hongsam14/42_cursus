/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/08 18:41:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.c"

static int		read_specifier(char **format, t_format *f_info)
{
	char		*tmp;

	tmp = *format;
	if (ft_strchr("cspdiuxX", *tmp) || *tmp == '%')
	{
		if ((f_info->flag & FLAG_ZERO) == FLAG_ZERO)
			if (ft_strchr("csp", *tmp))
				return (0);
		if ((f_info->flag & FLAG_DOT) == FLAG_DOT)
			if (ft_strchr("cp", *tmp))
				return (0);
		if ((f_info->flag & 3) == 3 && *tmp != '%')
			return (0);
		f_info->specifier = *tmp;
		tmp++;
	}
	else
	{
		f_info->specifier = 0;
		return (0);
	}
	*format = tmp;
	return (1);
}

static int		read_precision(char **format, t_format *f_info, va_list *v_lst)
{
	char		*tmp;
	int			read_pre;

	read_pre = 0;
	if (*(tmp = *format) == '.')
	{
		f_info->flag |= FLAG_DOT;
		if (*(++tmp) == '*')
		{
			tmp++;
			read_pre = va_arg(*v_lst, int);
			if (((f_info->flag & FLAG_ZERO) == FLAG_ZERO) && read_pre < 0)
				return (0);
		}
		else
		{
			while (*tmp >= '0' && *tmp <= '9')
				read_pre = (read_pre * 10) + (*(tmp++) - '0');
			if (read_pre < 0)
				return (0);
		}
		f_info->precision = read_pre;
	}
	*format = tmp;
	return (read_specifier(format, f_info));
}

static int		read_width(char **format, t_format *f_info, va_list *v_lst)
{
	char		*tmp;
	int			read_int;

	read_int = 0;
	tmp = *format;
	if (*tmp == '*')
	{
		tmp++;
		read_int = va_arg(*v_lst, int);
		if (((f_info->flag & FLAG_ZERO) == FLAG_ZERO) && read_int < 0)
			return (0);
	}
	else
	{
		while (*tmp >= '0' && *tmp <= '9')
		{
			read_int = (read_int * 10) + (*tmp - '0');
			tmp++;
		}
		if (read_int < 0)
			return (0);
	}
	f_info->width = read_int;
	*format = tmp;
	return (read_precision(format, f_info, v_lst));
}

static int		read_flag(char **format, t_format *f_info, va_list *v_lst)
{
	char		*tmp;

	tmp = *format + 1;
	while (ft_strchr("-0", *tmp))
	{
		if (*tmp == '-')
		{
			f_info->flag |= FLAG_MINUS;
			tmp++;
		}
		else
		{
			f_info->flag |= FLAG_ZERO;
			tmp++;
		}
	}
	*format = tmp;
	return (read_width(format, f_info, v_lst));
}

int				read_format(char *format, t_format **f_info, va_list *v_lst)
{
	char		*tmp;
	t_format	*f_tmp;
	t_format	*output;

	tmp = format;
	f_tmp = 0;
	output = *f_info;
	while ((tmp = ft_strchr(tmp, '%')))
	{
		if (init_t_format(&f_tmp) < 1)
			return (del_t_format(&output));
		if ((read_flag(&tmp, f_tmp, v_lst)) < 1)
		{
			free(f_tmp);
			return (del_t_format(&output));
		}
		add_back_t_format(&output, f_tmp);
	}
	*f_info = output;
	return (1);
}
