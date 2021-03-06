/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_di_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 01:47:06 by suhong            #+#    #+#             */
/*   Updated: 2020/11/20 19:35:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_size(int src)
{
	int		digit;

	digit = 1;
	if (src == -2147483648)
		return (10);
	if (src < 0)
		src *= -1;
	while ((src = src / 10))
		digit++;
	return (digit);
}

static int	prec_size(int src, t_format f_info)
{
	int		num_size;
	int		total;

	num_size = digit_size(src);
	if ((f_info.flag & FLAG_DOT))
	{
		if (num_size > f_info.precision)
			return (total = src == 0 ? 0 : num_size);
		else
			return (f_info.precision);
	}
	else
		return (num_size);
}

static int	print_num(int src, int num_len)
{
	int		remain;
	int		byte;

	byte = src == 0 ? 0 : 1;
	if (!src)
	{
		while (byte++ < num_len)
			ft_putchar_fd('0', 1);
		return (--byte);
	}
	if (src < 0)
	{
		if (src == -2147483648)
		{
			byte = 10 + print_num(0, num_len - 10);
			ft_putstr_fd("2147483648", 1);
			return (byte);
		}
		src *= -1;
	}
	remain = src % 10;
	byte += print_num(src / 10, --num_len);
	ft_putchar_fd('0' + remain, 1);
	return (byte);
}

static int	print_di(int src, int num_len, t_format f_info)
{
	int		byte;

	byte = 0;
	if (src < 0 && !(f_info.flag & FLAG_ZERO))
	{
		ft_putchar_fd('-', 1);
		byte++;
		num_len--;
	}
	byte += print_num(src, num_len);
	return (byte);
}

int			read_di_type(int src, t_format f_info)
{
	int		width;
	int		num_len;
	int		byte;
	int		total;

	byte = 0;
	num_len = src < 0 ? prec_size(src, f_info) + 1 : prec_size(src, f_info);
	width = num_len > f_info.width ? num_len : f_info.width;
	total = width - num_len;
	if (src < 0 && (f_info.flag & FLAG_ZERO))
	{
		ft_putchar_fd('-', 1);
		byte++;
		num_len--;
	}
	while (total >= 0)
	{
		if ((total == width - num_len && (f_info.flag & FLAG_MINUS))
				|| (total == 0 && !(f_info.flag & FLAG_MINUS)))
			byte += print_di(src, num_len, f_info);
		else
			byte += print_space_by_flag(f_info);
		total--;
	}
	return (byte);
}
