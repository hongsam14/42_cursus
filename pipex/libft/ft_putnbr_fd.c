/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:34:18 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 23:40:49 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	make_positive(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		return (-n);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		tmp;
	int		digit;
	char	i;

	digit = 1;
	i = '0';
	n = make_positive(n, fd);
	if (!n)
		return ;
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		digit *= 10;
	}
	while (digit > 0)
	{
		i = '0' + n / digit;
		n = n % digit;
		write(fd, &i, 1);
		digit = digit / 10;
	}
}
