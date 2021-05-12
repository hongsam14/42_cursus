/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:33 by suhong            #+#    #+#             */
/*   Updated: 2021/05/12 15:34:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include "header/common.h"
#include <stdio.h>

static int	init_a_b_stack(t_stack **a, t_stack **b)
{
	if (stack_init(a) == ERROR || stack_init(b) == ERROR)
	{
		if (a)
			stack_destroy(*a);
		if (b)
			stack_destroy(*b);
		return (0);
	}
	return (1);
}

static int	exit_checker(t_stack *a, t_stack *b)
{
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int	pivot_l;
	int	pivot_h;
	size_t	size;

	pivot_l = 0;
	pivot_h = 0;
	if (argc < 2)
		return (0);
	if (!init_a_b_stack(&a_stack, &b_stack))
		return (0);
	if (!put_int_2_stack(a_stack, argc, argv))
	{
		write(2, "Error\n", 6);
		return (exit_checker(a_stack, b_stack));
	}
	size = get_stack_size(*a_stack);
#if 0 
	get_pivot(a_stack, &size, &pivot_l, &pivot_h);
	printf("pl:%d, ph:%d\n", pivot_l, pivot_h);
#else
	if (a_2_b(a_stack, b_stack, size) == ERROR)
	{
		write(2, "Error\n", 6);
		return (exit_checker(a_stack, b_stack));
	}
#endif
	//printf("%d\n", step_count(0));
	return (exit_checker(a_stack, b_stack));
}
