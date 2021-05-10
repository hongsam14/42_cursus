/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:22:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/11 00:00:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

static int	get_middle(t_stack *stack, int comp, size_t size)
{
	t_deck	*p;
	int		diff;

	p = stack->tail;
	diff = 0;
	while (size--)
	{
		if (p->content > comp)
			diff += -1;
		else if(p->content < comp)
			diff += 1;
		else
			diff += 0;
		p = p->pre;
	}
	return (diff);
}

void	get_pivot(t_stack *stack, size_t size, int *p_l, int *p_h)
{
	t_deck	*p;
	int		diff;
	size_t	full_size;
	size_t	i;

	diff = 0;
	i = 0;
	p = stack->tail;
	full_size = get_stack_size(*stack);
	if (size > full_size)
		size = full_size;
	while (i++ < size)
	{
		diff = get_middle(stack, p->content, size);
		if (diff == -1 && (size % 2) == 0)
			break ;
		if (diff == size / 3)
			*p_h = p->content;
		if (diff == (-1 * size / 3))
			*p_l = p->content;
		p = p->pre;
	}
}
