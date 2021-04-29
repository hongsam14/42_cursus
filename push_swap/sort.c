/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:53:30 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 15:46:52 by suhong           ###   ########.fr       */
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

int			get_middle(t_stack *stack, int *middle, int *m_count)
{
	int		size;
	int		term;
	double	count;
	t_deck	*p;

	p = stack->head;
	term = 0;
	size = get_stack_size(*stack);
#if 1
	count = (size - 1) / 2;
	*m_count = (int)count;
#endif
	if (!(size % 2))
		term = -1;
	while (p != stack->tail)
	{
		if (go_round(p) == term)
		{
			*middle = p->content;
			return (OK);
		}
		p = p->next;
	}
	if (go_round(p) == term)
	{
		*middle = p->content;
		return (OK);
	}
	return (0);
}
