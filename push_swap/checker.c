/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:33 by suhong            #+#    #+#             */
/*   Updated: 2021/05/07 12:42:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/checker.h"

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

	if (argc < 2)
		return (0);
	if (!init_a_b_stack(&a_stack, &b_stack))
		return (0);
	if (!put_int_2_stack(a_stack, argc, argv))
	{
		write(1, "Error\n", 6);
		return (exit_checker(a_stack, b_stack));
	}
	if (get_input_str(a_stack, b_stack) == ERROR)
	{
		write(1, "Error\n", 6);
		return (exit_checker(a_stack, b_stack));
	}
	if (sort_check(a_stack) && stack_empty(b_stack))
		write(1, "\nOK\n", 4);
	else
		write(1, "\nKO\n", 4);
	exit_checker(a_stack, b_stack);
	return (0);
}
