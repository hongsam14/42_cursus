/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:55:26 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 11:55:18 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s)
{
	char			*p;
	int				i;
	int				size;

	size = ft_strlen(s);
	i = 0;
	if ((p = (char *)malloc((size + 1) * sizeof(char))) == 0)
		return (0);
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
