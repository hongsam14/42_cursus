/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:26:12 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 23:01:25 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_sign(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_is_num(const char *nptr)
{
	int				i;
	long long		num;
	long long		temp;
	int				sign;

	i = 0;
	num = 0;
	temp = 0;
	sign = 1;
	if (!nptr)
		return (ERROR);
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (ft_isdigit(nptr[i]))
		i++;
	if (nptr[i] != 0)
		return (ERROR);
	return (SUCCESS);
}

long long	ft_atoi(const char *nptr)
{
	long long			num;
	int					sign;
	int					i;
	int					cnt;

	i = 0;
	sign = 1;
	num = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	cnt = i;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != 0)
		return (ERROR);
	return (num * sign);
}
