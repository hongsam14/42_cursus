/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:45:04 by suhong            #+#    #+#             */
/*   Updated: 2020/10/08 03:02:15 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	i = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	while (i < s_size && i + d_size + 1 < size)
	{
		dst[d_size + i] = src[i];
		i++;
	}
	if (d_size < size)
	{
		dst[d_size + i] = '\0';
		return (d_size + s_size);
	}
	else
		return (s_size + size);
}
