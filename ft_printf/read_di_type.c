/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_di_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:47:06 by suhong            #+#    #+#             */
/*   Updated: 2020/11/15 10:13:51 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_size(int src)
{
	int		i;

	i = 0;
	if (src == -2147483648)
		return (11);
	if (src == 0)
		return (1);
	if (src < 0)
	{
		src *= -1;
		i++;
	}
	while (src)
	{
		src = src / 10;
		i++;
	}
	return (i);
}

static int	precision_size(int src, int s_size, t_format f_info)
{
	if ((f_info.flag & FLAG_DOT) == FLAG_DOT)
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

static void	print_di(int src, int len, int s_len)
{
	int		i;

	i = 0;
	if (src < 0)
		ft_putchar_fd('-', 1);
	while (i++ < len - s_len)
		ft_putchar_fd('0', 1);
	if (len > 0)
	{
		if (src == -2147483648)
		{
			ft_putstr_fd("2147483648", 1);
			return ;
		}
		src = src > 0 ? src : -src;
		ft_putnbr_fd(src, 1);
	}
}

int			read_di_type(int src, t_format f_info)
{
	int		s_len;
	int		len;
	int		width;
	int		i;

	i = 0;
	s_len = digit_size(src);
	len = precision_size(src, s_len, f_info);
	width = len > f_info.width ? len : f_info.width;
	while (i <= width - len)
	{
		if ((i == 0 && (f_info.flag & FLAG_MINUS) == FLAG_MINUS)
				|| (i == width - len
					&& (f_info.flag & FLAG_MINUS) != FLAG_MINUS))
			print_di(src, len, s_len);
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
