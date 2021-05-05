/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:53:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/04 18:45:30 by suhong           ###   ########.fr       */
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

#if 1
static int	pre_work(t_stack *a, t_stack *b)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		if (a->tail->pre->content < a->tail->content)
		{
			if (!stack_empty(b) && !stack_one_left(b)
					&& b->tail->pre->content > b->tail->content)
			{
				if (dble_order(a, b, swap_order) == ERROR)
					return (ERROR);
			}
			else
				if (swap_order(a) == ERROR)
					return (ERROR);
			step_count(1);
			print_a_b_stack(a, b);
		}
		else if (a->head->content < a->tail->content)
		{
			if (!stack_empty(b) && !stack_one_left(b)
					&& b->head->content > b->tail->content)
				dble_order(a, b, rev_rotate_order);
			else
				rev_rotate_order(a);
			step_count(1);
			print_a_b_stack(a, b);
		}
		else
			flag = 0;
	}
	return (1);
}

static int	pre_b_work(t_stack *a, t_stack *b)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		if (b->tail->pre->content > b->tail->content)
		{
			if (swap_order(b) == ERROR)
				return (ERROR);
			step_count(1);
			print_a_b_stack(a, b);
		}
		else if (b->head->content > b->tail->content)
		{
			rev_rotate_order(b);
			step_count(1);
			print_a_b_stack(a, b);
		}
		else
			flag = 0;
	}
	return (1);
}
#endif
int	push_little(t_stack *a, t_stack *b, int mid, int m_count)
{
	if (m_count <= 0)
		return (step_count(0));
	if (pre_work(a, b) == ERROR)
		return (ERROR);
	while (a->tail->content >= mid)
	{
		rotate_order(a);
		print_a_b_stack(a, b);
		step_count(1);
	}
	if (!sort_check(a))
	{
		if (push_order(a, b) == ERROR)
			return (ERROR);
		print_a_b_stack(a, b);
		step_count(1);

	}
	else
		if (stack_empty(b))
			return (step_count(0));
	return (push_little(a, b, mid, --m_count));
}

int	push_big(t_stack *a, t_stack *b, int mid, int m_count)
{
	if (m_count <= 0)
		return (step_count(0));
#if 1
	if (pre_b_work(a, b) == ERROR)
		return (ERROR);
#endif
	while (b->tail->content <= mid)
	{
		rotate_order(b);
		print_a_b_stack(a, b);
		step_count(1);
	}
	if (push_order(b, a) == ERROR)
		return (ERROR);
	print_a_b_stack(a, b);
	step_count(1);
	if (pre_work(a, b) == ERROR)
		return (ERROR);
	return (push_big(a, b, mid, --m_count));
}
