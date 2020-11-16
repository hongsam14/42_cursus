/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_percent_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:59:55 by suhong            #+#    #+#             */
/*   Updated: 2020/11/15 14:19:25 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_percent_type(t_format f_info)
{
	int		width;
	int		byte;

	width = f_info.width > 0 ? f_info.width : 1;
	byte = 0;
	while (byte < width)
	{
		if ((f_info.flag & FLAG_MINUS) == FLAG_MINUS)
		{
			if (byte == 0)
				ft_putchar_fd('%', 1);
			else
				print_space_by_flag(f_info);
		}
		else
		{
			if (byte == width - 1)
				ft_putchar_fd('%', 1);
			else
				print_space_by_flag(f_info);
		}
		byte++;
	}
	return (byte);
}
