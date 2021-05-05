/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:33 by suhong            #+#    #+#             */
/*   Updated: 2021/05/05 16:31:53 by suhong           ###   ########.fr       */
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
	int	middle;
	int	m_count;
	int	step;

	middle = 0;
	m_count = 0;
	step = 0;
	if (argc < 2)
		return (0);
	if (!init_a_b_stack(&a_stack, &b_stack))
		return (0);
	if (!put_int_2_stack(a_stack, argc, argv))
	{
		write(1, "Error\n", 6);
		return (exit_checker(a_stack, b_stack));
	}
#if 0
	while (!sort_check(a_stack))
		step = push_a_2_b(a_stack, b_stack);
	push_b_all(a_stack, b_stack);
#else
	step = push_a_2_b(a_stack, b_stack);
	push_b_all(a_stack, b_stack);
#endif
#if 0
	if (step != ERROR)
		printf("step:%d\n", step_count(0));
#endif
	exit_checker(a_stack, b_stack);
	return (0);
}
