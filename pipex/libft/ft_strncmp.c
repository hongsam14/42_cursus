/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:17:58 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 23:18:21 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*b;

	i = 0;
	f = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && f[i] != '\0' && b[i] != '\0')
	{
		if (f[i] > b[i])
			return (1);
		if (b[i] > f[i])
			return (-1);
		i++;
	}
	if (i < n)
	{
		if (f[i] != '\0')
			return (1);
		if (b[i] != '\0')
			return (-1);
	}
	return (0);
}
