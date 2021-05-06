/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:05:05 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 23:12:34 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	c_tmp;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	c_tmp = c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c_tmp)
			return (&d[i + 1]);
		i++;
	}
	return (0);
}
