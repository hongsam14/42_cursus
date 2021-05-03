/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:53:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/03 14:51:12 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

static int	go_round(t_deck *start)
{
	int		cont;
	int		diff;
	t_deck	*p;

	diff = 0;
	cont = start->content;
	p = start->next;
	while (p != start)
	{
		if (cont < p->content)
			diff += 1;
		else if (cont > p->content)
			diff += -1;
		else
			diff += 0;
		p = p->next;
	}
	return (diff);
}

int	get_middle(t_stack *stack, int *middle, int *m_count)
{
	int		size;
	int		term;
	t_deck	*p;

	p = stack->head;
	term = 0;
	size = get_stack_size(*stack);
	if (size <= 2)
		return (0);
	*m_count = (size - 1) / 2;
	if (!(size % 2))
		term = -1;
	while (p != stack->tail && go_round(p) != term)
		p = p->next;
	if (go_round(p) == term)
	{
		*middle = p->content;
		return (OK);
	}
	return (0);
}

pre

int	push_little(t_stack *a, t_stack *b, int mid, int m_count)
{
	if (m_count <= 0)
		return (step_count(0));
	if (a->tail->pre->content < a->tail->content)
	{
		if (swap_order(a) == ERROR)
			return (ERROR);
		print_a_b_stack(a, b);
		step_count(1);
	}
	while (a->tail->content >= mid)
	{
		if (a->tail->pre->content < mid)
		{
			if (swap_order(a) == ERROR)
				return (ERROR);
		}
		else if (a->head->content < mid)
			rev_rotate_order(a);
		else
			rotate_order(a);
		print_a_b_stack(a, b);
		step_count(1);
	}
	if (sort_check(a) && stack_empty(b))
		return (step_count(0));
	if (push_order(a, b) == ERROR)
		return (ERROR);
	print_a_b_stack(a, b);
	step_count(1);
	return (push_little(a, b, mid, --m_count));
}

int	push_big(t_stack *a, t_stack *b, int mid, int m_count)
{
	if (m_count <= 0)
		return (step_count(0));
	while (b->tail->content <= mid)
	{
		if (b->tail->pre->content > mid)
		{
			if (swap_order(b) == ERROR)
				return (ERROR);
		}
		else if (b->head->content > mid)
			rev_rotate_order(b);
		else
			rotate_order(b);
		print_a_b_stack(a, b);
		step_count(1);
	}
	if (b->tail->pre->content > b->tail->content)
	{
		if (swap_order(b) == ERROR)
			return (ERROR);
		print_a_b_stack(a, b);
		step_count(1);
	}
	if (push_order(b, a) == ERROR)
		return (ERROR);
	print_a_b_stack(a, b);
	step_count(1);
	return (push_big(a, b, mid, --m_count));
}
