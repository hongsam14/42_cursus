/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_p_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:00:16 by suhong            #+#    #+#             */
/*   Updated: 2020/11/11 05:34:36 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			count_hex(unsigned long address)
{
	unsigned long	quata;
	int				byte;

	if (!address)
		return (2);
	byte = 1;
	quata = address / 16;
	byte += count_hex(quata);
	return (byte);
}

static void			print_hex(unsigned long address)
{
	char			remain;
	unsigned long	quata;

	if (!address)
	{
		ft_putstr_fd("0x", 1);
		return ;
	}
	quata = address / 16;
	remain = change_2_hex(address % 16, 0);
	print_hex(quata);
	write(1, &remain, 1);
	return ;
}

static void			print_address(unsigned long address)
{
	if (!address)
		ft_putstr_fd("0x0", 1);
	else
		print_hex(address);
}

int					read_p_type(void *src, t_format f_info)
{
	unsigned long	address;
	int				byte;
	int				width;
	int				ad_size;

	byte = 0;
	address = (unsigned long)src;
	ad_size = address == 0 ? 3 : count_hex(address);
	width = ad_size > f_info.width ? ad_size : f_info.width;
	while (byte <= width - ad_size)
	{
		if ((byte == 0
					&& (f_info.flag & FLAG_MINUS) == FLAG_MINUS)
				|| (byte == width - ad_size
					&& (f_info.flag & FLAG_MINUS) != FLAG_MINUS))
			print_address(address);
		else
			ft_putchar_fd(' ', 1);
		byte++;
	}
	return (width);
}
