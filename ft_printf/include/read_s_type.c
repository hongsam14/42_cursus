/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_s_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:19:20 by suhong            #+#    #+#             */
/*   Updated: 2020/11/20 19:28:57 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		precision_size(char *src, t_format f_info)
{
	int			src_len;

	if (src == 0)
		src_len = 6;
	else
		src_len = ft_strlen(src);
	if ((f_info.flag & FLAG_DOT))
	{
		if (f_info.precision > src_len)
			return (src_len);
		else
			return (f_info.precision);
	}
	else
		return (src_len);
}

static void		print_src(char *src, int len)
{
	if (src == 0)
		write(1, "(null)", len);
	else
		write(1, src, len);
}

int				read_s_type(char *src, t_format f_info)
{
	int			byte;
	int			s_len;
	int			width;

	byte = 0;
	s_len = precision_size(src, f_info);
	width = s_len > f_info.width ? s_len : f_info.width;
	while (byte <= width - s_len)
	{
		if ((f_info.flag & FLAG_MINUS))
		{
			if (byte++ == 0)
				print_src(src, s_len);
			else
				print_space_by_flag(f_info);
		}
		else
		{
			if (byte++ == width - s_len)
				print_src(src, s_len);
			else
				print_space_by_flag(f_info);
		}
	}
	return (width);
}
