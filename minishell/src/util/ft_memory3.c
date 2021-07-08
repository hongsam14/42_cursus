/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:19:49 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 01:53:20 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_isprint(int n)
{
	char	c;

	c = (char)n;
	return (c >= 32 && c < 127);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
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

char	*ft_strchr(const char *s, char c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
