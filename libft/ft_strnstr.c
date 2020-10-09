/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:10:41 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 11:36:12 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (i < len && str[i] != '\0')
	{
		tmp = 0;
		while (i + tmp < len && to_find[tmp] == str[tmp + i])
		{
			tmp++;
			if (to_find[tmp] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
