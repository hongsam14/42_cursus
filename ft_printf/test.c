/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <ghdtjdgus14@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:57:42 by suhong            #+#    #+#             */
/*   Updated: 2020/11/10 12:01:21 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void		test(int count, ...)
{
	va_list	lst;

	va_start(lst, count);
	printf("%d\n", va_arg(lst, int));
	va_end(lst);
}

int			main(void)
{
	//char		c = 'A';

	printf("%d\n", printf("%p\n", ""));
	return (0);
}
