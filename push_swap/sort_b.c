/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:36:56 by suhong            #+#    #+#             */
/*   Updated: 2021/05/03 22:40:21 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static int	sort_a_remain(t_stack *a, t_stack *b)
{
	if (stack_empty(a) || stack_one_left(a))
		return (1);
	if (a->tail->content > a->tail->pre->content)
	{
		swap_order(a);
		print_a_b_stack(a, b);
		step_count(1);
	}
	return (1);
}

static int	sort_b_remain(t_stack *a, t_stack *b)
{
	if (stack_empty(b) || stack_one_left(b))
		return (1);
	if (b->tail->content < b->tail->pre->content)
	{
		swap_order(b);
		print_a_b_stack(a, b);
		step_count(1);
	}
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
		ft_putstr_fd("----start----\n", 1);
		old_step = step;
		step = push_little(a, b, middle, m_count);
		if (step == ERROR)
			return (ERROR);
	}
	ft_putstr_fd("-----end-----\n", 1);
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
		ft_putstr_fd("----start----\n", 1);
		old_step = step;
		step = push_big(a, b, middle, m_count);
		if (step == ERROR)
			return (ERROR);
	}
	ft_putstr_fd("-----end-----\n", 1);
	sort_b_remain(a, b);
	return (step);
}

int	push_b_all(t_stack *a, t_stack *b)
{
#if 1
	while (!stack_empty(b))
	{
		if (push_order(b, a) == ERROR)
			return (ERROR);
		print_a_b_stack(a, b);
		step_count(1);
	}
#endif
	return (OK);
}
