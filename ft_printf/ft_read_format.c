/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:42:27 by suhong            #+#    #+#             */
/*   Updated: 2020/11/03 16:54:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		read_dec;

	tmp = *format;
	read_dec = 0;
	if (*tmp == '.')
	{
		tmp++;
		f_info->flag |= flag_dot;
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
	return (read_specifier(&tmp, f_info));
}

static int		read_width(char **format, t_format *f_info)
{
	char		*tmp;
	int		read_int;
	
	tmp = *format;
	read_int = 0;
	while (*tmp >= '0' && *tmp <= '9')
	{
		read_int = (read_int * 10) + (*tmp - '0');
		tmp++;
	}
	if (read_int < 0)
		return (0);
	f_info->width = read_int;
	*format = tmp;
	return (read_decimal(&tmp, f_info));
}

static int		read_flag(char	**format, t_format *f_info)
{
	char		*tmp;
	int		tmp_flag;

	tmp = *format;
	tmp_flag = 0;
	while (ft_strchr("-0*", *tmp))
	{
		if (*tmp == '-')
			tmp_flag = flag_minus;
		else if (*tmp == '0')
			tmp_flag = flag_zero;
		else if (*tmp == '*')
			tmp_flag = flag_star;
		if ((*f_info).flag & tmp_flag == tmp_flag)
			return (0);
		else
			f_info->flag |= tmp_flag;
		tmp++;
	}
	*format = tmp;
	return (read_width(&tmp, f_info));
}

int			read_format(char *format, t_format *format_info)
{
	char		*tmp;
	t_format	*f_info;
	t_format	*f_tmp;

	tmp = format;
	f_info = format_info;
	while (tmp = ft_strchr(tmp, '%'))
	{
		tmp++;
		if ((read_flag(&tmp, f_info)) < 1 || f_info->flag == 3 || f_info->flag == 12)
			return (0);
		if ((f_tmp = (t_format *)malloc(sizeof(t_format))) == 0)
		{
			return (0);
		}
		f_tmp->next = 0;
		f_info->next = f_tmp;
		f_info = f_info->next
		tmp++;
	}
	return (1);
}
