/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:47:22 by suhong            #+#    #+#             */
/*   Updated: 2021/05/10 16:12:50 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

int	quick_a_2_b(t_stack *a, t_stack *b, size_t size)
{
	int	pivot;
	size_t	ra_log;
	size_t	pb_log;
	size_t	i;

	pivot = 0;
	ra_log = 0;
	pb_log = 0;
	i = 0;
	if (size < 2)
		return (1);
	pivot = get_pivot(a, size);
	while (size-- && !stack_empty(a))
	{
		if (a->tail->content > pivot)
		{
			print_order("ra", a, b);
			ra_log++;
		}
		else
		{
			if (print_order("pb", a, b) == ERROR)
				return (ERROR);
			pb_log++;
		}
	}
	while (i++ < ra_log)
		print_order("rra", a, b);
	quick_a_2_b(a, b, ra_log);
	quick_b_2_a(a, b, pb_log);
	return (1);
}

int	quick_b_2_a(t_stack *a, t_stack *b, size_t size)
{
	int	pivot;
	size_t	rb_log;
	size_t	pa_log;
	size_t	i;

	pivot = 0;
	rb_log = 0;
	pa_log = 0;
	i = 0;
	if (size < 2)
	{
		if (print_order("pa", a, b) == ERROR)
			return (ERROR);
		return (1);
	}
	pivot = get_pivot(b, size);
	while (size-- && !stack_empty(b))
	{
		if (b->tail->content <= pivot)
		{
			print_order("rb", a, b);
			rb_log++;
		}
		else
		{
			if (print_order("pa", a, b) == ERROR)
				return (ERROR);
			pa_log++;
		}
	}
	while (i++ < rb_log)
		print_order("rrb", a, b);
	quick_a_2_b(a, b, pa_log);
	quick_b_2_a(a, b, rb_log);
	return (1);
}
