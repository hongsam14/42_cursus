/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:53:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/06 16:40:03 by suhong           ###   ########.fr       */
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
				if (print_order("ss", a, b) == ERROR)
					return (ERROR);
			}
			else
				if (print_order("sa", a, b) == ERROR)
					return (ERROR);
		}
		else if (a->head->content < a->tail->content)
		{
			if (!stack_empty(b) && !stack_one_left(b)
					&& b->head->content > b->tail->content)
				print_order("rrr", a, b);
			else
				print_order("rra", a, b);
		}
		else
			flag = 0;
	}
	return (1);
}
#if 1
static int	pre_b_work(t_stack *a, t_stack *b)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		if (b->tail->pre->content > b->tail->content)
		{
			if (print_order("sb", a, b) == ERROR)
				return (ERROR);
		}
		else if (b->head->content > b->tail->content)
			print_order("rrb", a, b);
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
#if 1
	if (pre_work(a, b) == ERROR)
		return (ERROR);
#endif
	while (a->tail->content >= mid)
		print_order("ra", a, b);
#if 1
	if (pre_work(a, b) == ERROR)
		return (ERROR);
#endif
	if (!sort_check(a))
	{
		if (print_order("pb", a, b) == ERROR)
			return (ERROR);
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
#if 0
	if (pre_b_work(a, b) == ERROR)
		return (ERROR);
#endif
	while (b->tail->content <= mid)
		print_order("rb", a, b);
#if 1
	if (pre_b_work(a, b) == ERROR)
		return (ERROR);
#endif
	if (print_order("pa", a, b) == ERROR)
		return (ERROR);
	if (pre_work(a, b) == ERROR)
		return (ERROR);
	return (push_big(a, b, mid, --m_count));
}
