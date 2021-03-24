/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:47:36 by suhong            #+#    #+#             */
/*   Updated: 2021/03/24 18:09:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		write_little_endian(unsigned char *dest, int value)
{
	size_t	size;
	int		i;

	i = 0;
	size = sizeof(int);
	while (i < size)
	{
		dest[i] = (value >> (8 * i));
		i++;
	}
}

void		write_file_header(unsigned char *dest, int file_size, int *start)
{
	dest[0] = 'B';
	dest[1] = 'M';
	write_little_endian(&dest[2], file_size);
	dest[6] = 0;
	dest[7] = 0;
	dest[8] = 0;
	dest[9] = 0;
	write_little_endian(&dest[10], 54);
}

void		write_info_header(unsigned char *dest, int w, int h)
{
	write_little_endian(&dest[0], 40);
	write_little_endian(&dest[4], w);
	write_little_endian(&dest[8], h);
	dest[12] = 1;
	dest[13] = 24;
} 
