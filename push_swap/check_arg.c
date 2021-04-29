/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:24:58 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 01:23:00 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/common.h"

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

static int	check_dup(t_stack *stack, int cont)
{
	t_deck	*p;

	if (stack_empty(stack))
		return (OK);
	p = stack->head;
	while (p != stack->tail)
	{
		if (cont == p->content)
			return (0);
		p = p->next;
	}
	if (cont == p->content)
		return (0);
	return (1);
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
		if (!check_dup(stack, out))
			return (0);
		push(stack, out);
		argc--;
	}
	return (1);
}
