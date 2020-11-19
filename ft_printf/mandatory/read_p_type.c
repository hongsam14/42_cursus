/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_p_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:00:16 by suhong            #+#    #+#             */
/*   Updated: 2020/11/18 20:11:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			count_hex(unsigned long address)
{
	int				byte;

	byte = 1;
	while ((address = address / 16))
		byte++;
	return (byte);
}

static int			prec_size(unsigned long address, t_format f_info)
{
	int				size;

	size = count_hex(address);
	if ((f_info.flag & FLAG_DOT))
	{
		if (!f_info.precision && !address)
			return (0);
		if (size > f_info.precision)
			return (size);
		else
			return (f_info.precision);
	}
	else
		return (size);
}

static int			print_hex(unsigned long address, int size)
{
	char			remain;
	unsigned long	quata;
	int				byte;

	byte = address == 0 ? 0 : 1;
	if (!address)
	{
		ft_putstr_fd("0x", 1);
		while (size--)
		{
			ft_putchar_fd('0', 1);
			byte++;
		}
		return (byte + 2);
	}
	quata = address / 16;
	remain = change_2_hex(address % 16, 0);
	byte += print_hex(quata, --size);
	write(1, &remain, 1);
	return (byte);
}

int					read_p_type(void *src, t_format f_info)
{
	unsigned long	address;
	int				byte;
	int				width;
	int				ad_size;

	byte = 0;
	address = (unsigned long)src;
	ad_size = prec_size(address, f_info) + 2;
	width = ad_size > f_info.width ? ad_size : f_info.width;
	while (byte < width)
	{
		if ((byte == 0
					&& (f_info.flag & FLAG_MINUS))
				|| (byte == width - ad_size
					&& !(f_info.flag & FLAG_MINUS)))
			byte += print_hex(address, ad_size - 2);
		else
		{
			ft_putchar_fd(' ', 1);
			byte++;
		}
	}
	return (byte);
}
