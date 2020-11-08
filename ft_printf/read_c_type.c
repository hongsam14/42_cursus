/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_c_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:07:32 by suhong            #+#    #+#             */
/*   Updated: 2020/11/08 18:19:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_c_type(char src, t_format f_info)
{
	int		byte;
	int		width;

	byte = 0;
	width = f_info.width > 0 ? f_info.width : 1;
	while (byte < width)
	{
		if ((f_info.flag & FLAG_MINUS) == FLAG_MINUS)
		{
			if (byte == 0)
				ft_putchar_fd(src, 1);
			else
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (byte == width - 1)
				ft_putchar_fd(src, 1);
			else
				ft_putchar_fd(' ', 1);
		}
		byte++;
	}
	return (byte);
}
