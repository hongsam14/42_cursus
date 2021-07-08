/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:11:15 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 07:36:56 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_add_char(char **str, char c, int pt)
{
	int		len;
	char	*result;

	pt--;
	len = ft_strlen((*str));
	if (!(ft_malloc(&result, sizeof(char) * (len + 2))))
		return (0);
	if ((*str))
		ft_memcpy(result, (*str), pt);
	result[pt] = c;
	ft_memcpy(result + pt + 1, (*str) + pt, len - pt);
	result[len + 1] = 0;
	ft_free((*str));
	(*str) = 0;
	return (result);
}

char	*ft_del_char(char **str, int pt)
{
	int		len;
	char	*result;

	result = 0;
	len = ft_strlen((*str));
	if (len <= 0 || pt < 1)
		return (0);
	if (!(ft_malloc(&result, sizeof(char) * (len))))
		return (0);
	if (pt >= 1)
		ft_memcpy(result, (*str), pt - 1);
	ft_memcpy(result + pt - 1, (*str) + pt, len - pt);
	result[len - 1] = 0;
	ft_free((*str));
	(*str) = 0;
	return (result);
}
