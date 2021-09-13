/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:36:43 by suhong            #+#    #+#             */
/*   Updated: 2021/09/12 14:47:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		digit;
	int		sign;
	int		tmp;
	char	*p;

	sign = 1;
	tmp = 0;
	digit = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	p = (char *)nptr;
	while (p[digit] != '\0' && (p[digit] >= '0' && p[digit] <= '9'))
		tmp = (tmp * 10) + (p[digit++] - '0');
	if (digit >= 19)
		return (tmp = sign & 0x10000000);
	return (tmp * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
