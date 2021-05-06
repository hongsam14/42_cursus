/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:36:56 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 16:36:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static int	sort_a_remain(t_stack *a, t_stack *b)
{
	if (stack_empty(a) || stack_one_left(a))
		return (1);
	if (a->tail->content > a->tail->pre->content)
		print_order("sa", a, b);
	return (1);
}

static int	sort_b_remain(t_stack *a, t_stack *b)
{
	if (stack_empty(b) || stack_one_left(b))
		return (1);
	if (b->tail->content < b->tail->pre->content)
		print_order("sa", a, b);
	return (1);
}

int	push_a_2_b(t_stack *a, t_stack *b)
{
	int	middle;
	int	m_count;
	int	step;
	int	old_step;

	step = 0;
	old_step = -1;
	while (get_middle(a, &middle, &m_count) && step > old_step)
	{
		old_step = step;
		step = push_little(a, b, middle, m_count);
		if (step == ERROR)
			return (ERROR);
	}
	sort_a_remain(a, b);
	return (push_b_2_a(a, b));
}

int	push_b_2_a(t_stack *a, t_stack *b)
{
	int	middle;
	int	m_count;
	int	step;
	int	old_step;

	step = 0;
	old_step = -1;
	while (get_middle(b, &middle, &m_count) && step > old_step)
	{
		old_step = step;
		step = push_big(a, b, middle, m_count);
		if (step == ERROR)
			return (ERROR);
	}
	sort_b_remain(a, b);
	return (step);
}

int	push_b_all(t_stack *a, t_stack *b)
{
	while (!stack_empty(b))
		if (print_order("pa", a, b) == ERROR)
			return (ERROR);
	return (OK);
}
