/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:34:59 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 02:21:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	ft_malloc(void *target, int size)
{
	void		**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == NULLPTR)
		return (FALSE);
	return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned char	*c;
	size_t			i;

	i = 0;
	p = (void *)malloc(nmemb * size);
	if (!p)
		ft_error("malloc error");
	c = p;
	while (i++ < nmemb * size)
		*c++ = 0;
	return (p);
}
