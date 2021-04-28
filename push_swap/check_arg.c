/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:24:58 by suhong            #+#    #+#             */
/*   Updated: 2021/04/28 12:27:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/io.h"
#include <stdio.h>

static int	check_str_int(char *str)
{
	int	i;
	int	state;

	i = 0;
	state = 1;
	if (ft_strchr("+-", *str))
	{
		if (*str == '-')
			state = -1;
		str++;
	}
	while (str[i])
		if (!ft_strchr("0123456789", str[i++]))
			return (0);
	if (i == 0 || i > 10 || (i == 10 && *str - '0' > 2))
		return (0);
	return (state);
}

int	put_int_2_stack(t_stack *stack, int argc, char *argv[])
{
	long	state;
	int	out;

	while (argc > 1)
	{
		state = check_str_int(argv[argc - 1]);
		if (!state)
			return (0);
		out = atoi(argv[argc - 1]);
		state *= out;
		if (state < 0)
			return (0);
		push(stack, out);
		argc--;
	}
	return (1);
}
