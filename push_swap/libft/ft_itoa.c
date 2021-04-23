/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:32:06 by suhong            #+#    #+#             */
/*   Updated: 2020/10/08 14:25:16 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_itoa(int n)
{
	char		*tmp;
	size_t		size;
	int			minus;

	if (n == -2147483648 || n == 0)
	{
		tmp = n == 0 ? ft_strdup("0") : ft_strdup("-2147483648");
		return (tmp);
	}
	minus = n < 0 ? 1 : 0;
	size = n < 0 ? digit_size(n *= -1) + 1 : digit_size(n);
	if ((tmp = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	tmp[size] = '\0';
	while (n > 0)
	{
		tmp[size - 1] = '0' + n % 10;
		n = n / 10;
		size--;
	}
	if (minus)
		tmp[0] = '-';
	return (tmp);
}
