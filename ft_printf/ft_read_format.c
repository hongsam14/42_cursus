/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/04 22:03:48 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.c"
#include <stdio.h>

static int		read_specifier(char **format, t_format *f_info)
{
	char		*tmp;

	tmp = *format;
	if (ft_strchr("cspdiuxX", *tmp))
		f_info->specifier = *tmp;
	else
	{
		f_info->specifier = 0;
		return (0);
	}
	*format = tmp;
	return (1);
}

static int		read_decimal(char **format, t_format *f_info)
{
	char		*tmp;
	int			read_dec;

	tmp = *format;
	read_dec = 0;
	if (*tmp == '.')
	{
		tmp++;
		f_info->flag |= FLAG_DOT;
		while (*tmp >= '0' && *tmp <= '9')
		{
			read_dec = (read_dec * 10) + (*tmp - '0');
			tmp++;
		}
		if (read_dec < 0)
			return (0);
		f_info->decimal = read_dec;
	}
	*format = tmp;
	return (read_specifier(format, f_info));
}

static int		read_width(char **format, t_format *f_info)
{
	char		*tmp;
	int			read_int;

	read_int = 0;
	tmp = *format;
	while (*tmp >= '0' && *tmp <= '9')
	{
		read_int = (read_int * 10) + (*tmp - '0');
		tmp++;
	}
	if (read_int < 0)
		return (0);
	f_info->width = read_int;
	*format = tmp;
	return (read_decimal(format, f_info));
}

static int		read_flag(char **format, t_format *f_info)
{
	char		*tmp;
	int			tmp_flag;

	tmp = *format + 1;
	tmp_flag = 0;
	while (ft_strchr("-0*", *tmp))
	{
		if (*tmp == '-')
			tmp_flag = FLAG_MINUS;
		else if (*tmp == '0')
			tmp_flag = FLAG_ZERO;
		else if (*tmp == '*')
			tmp_flag = FLAG_STAR;
		if ((f_info->flag & tmp_flag) == tmp_flag)
			return (0);
		else
			f_info->flag |= tmp_flag;
		tmp++;
	}
	*format = tmp;
	return (read_width(format, f_info));
}

int				read_format(char *format, t_format **f_info)
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
		if ((read_flag(&tmp, f_tmp)) < 1
				|| f_tmp->flag == 3 || f_tmp->flag == 12)
		{
			free(f_tmp);
			return (del_t_format(&output));
		}
		add_back_t_format(&output, f_tmp);
		printf("%d, %d, %d, %c\n", f_tmp->flag, f_tmp->width, f_tmp->decimal, f_tmp->specifier);
	}
	*f_info = output;
	return (1);
}
