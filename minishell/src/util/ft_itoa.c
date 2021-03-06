/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:32:06 by suhong            #+#    #+#             */
/*   Updated: 2021/07/04 23:01:25 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static size_t	digit_size(int n)
{
	int			i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*special_case(int n)
{
	char	*tmp;

	tmp = 0;
	if (n == 0)
		tmp = ft_strndup("0", ft_strlen("0"));
	if (n == -2147483648)
		tmp = ft_strndup("-2147483648", ft_strlen("-2147483648"));
	return (tmp);
}

static size_t	get_size(int *n, int *sign)
{
	size_t	size;

	size = 0;
	if (*n < 0)
	{
		size = 1;
		*sign = -1;
	}
	*n *= (*sign);
	size += digit_size(*n);
	return (size);
}

char	*ft_itoa(int n)
{
	char		*tmp;
	size_t		size;
	int			sign;

	sign = 1;
	tmp = special_case(n);
	if (tmp)
		return (tmp);
	size = get_size(&n, &sign);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (0);
	tmp[size] = '\0';
	while (n > 0)
	{
		tmp[size - 1] = '0' + n % 10;
		n = n / 10;
		size--;
	}
	if (sign < 0)
		tmp[0] = '-';
	return (tmp);
}
