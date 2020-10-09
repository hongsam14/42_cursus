/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:55:55 by suhong            #+#    #+#             */
/*   Updated: 2020/10/06 11:53:16 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*c;
	size_t			i;

	i = 0;
	if ((p = (void *)malloc(nmemb * size)) == 0)
		return (0);
	c = p;
	while (i++ < nmemb * size)
		*c++ = 0;
	return (p);
}
