/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ux_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:47:06 by suhong            #+#    #+#             */
/*   Updated: 2020/11/16 21:16:53 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			digit_size_ux(unsigned int src, t_format f_info)
{
	int				i;
	int				deno;

	i = 1;
	deno = f_info.specifier == 'u' ? 10 : 16;
	while ((src = src / deno))
		i++;
	return (i);
}

static int			precision_size_ux(unsigned int src
		, int s_size, t_format f_info)
{
	if ((f_info.flag & FLAG_DOT))
	{
		if (s_size > f_info.precision)
		{
			if (src == 0)
				return (0);
			else
				return (s_size);
		}
		return (f_info.precision);
	}
	return (s_size);
}

static void			print_hex_dec(unsigned int src, int deno, int capital)
{
	unsigned int	quata;
	unsigned int	remain;

	if (src == 0)
		return ;
	quata = src / deno;
	remain = src % deno;
	print_hex_dec(quata, deno, capital);
	ft_putchar_fd(change_2_hex(remain, capital), 1);
	return ;
}

static void			print_ux(unsigned int src, int len
		, int s_len, t_format f_info)
{
	int				i;

	i = 0;
	while (i++ < len - s_len)
		ft_putchar_fd('0', 1);
	if (len > 0)
	{
		if (src == 0)
		{
			ft_putchar_fd('0', 1);
			return ;
		}
		if (f_info.specifier == 'u')
			print_hex_dec(src, 10, 0);
		else
		{
			if (f_info.specifier == 'x')
				print_hex_dec(src, 16, 0);
			else
				print_hex_dec(src, 16, 1);
		}
	}
}

int					read_ux_type(unsigned int src, t_format f_info)
{
	int				s_len;
	int				len;
	int				width;
	int				i;

	i = 0;
	s_len = digit_size_ux(src, f_info);
	len = precision_size_ux(src, s_len, f_info);
	width = len > f_info.width ? len : f_info.width;
	while (i <= width - len)
	{
		if ((i == 0 && (f_info.flag & FLAG_MINUS))
				|| (i == width - len
					&& !(f_info.flag & FLAG_MINUS)))
			print_ux(src, len, s_len, f_info);
		else
		{
			if ((f_info.flag & FLAG_ZERO) == FLAG_ZERO)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	return (width);
}
