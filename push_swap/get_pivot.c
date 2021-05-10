/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:22:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/10 15:42:27 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

#if 0
static int	*make_array(t_deck *start, size_t size)
{
	int		*tmp;
	size_t		i;
	t_deck	*p;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	p = start;
	i = 0;
	while (i < size)
	{
		tmp[i] = p->content;
		p = p->pre;
		i++;
	}
	return (tmp);
}

static int	sort_array(int *array, int head, int tail)
{
	int	pivot;
	int	low;
	int	high;
	int	tmp;

	pivot = array[head];
	low = head + 1;
	high = tail;
	while (low <= high)
	{
		while (array[low] < pivot && low <= tail)
			low++;
		while (array[high] > pivot && high >= head)
			high--;
		if (low < high)
		{
			tmp = array[low];
			array[low] = array[high];
			array[high] = tmp;
		}
	}
	tmp = array[head];
	array[head] = array[high];
	array[high] = tmp;
	return (high);
}

static void	quick_sort(int *array, int head, int tail)
{
	int	pivot;

	if (head < tail)
	{
		pivot = sort_array(array, head, tail);
		quick_sort(array, head, pivot - 1);
		quick_sort(array, pivot + 1, tail);
	}
}

int	get_pivot(t_deck *start, size_t size, int *pivot)
{
	int				*tmp;
	size_t			i;

	i = 0;
	tmp = make_array(start, size);
	if (!tmp)
		return (0);
	quick_sort(tmp, 0, size - 1);
	i = size / 2;
	*pivot = tmp[i];
	free(tmp);
	return (1);
}
#else

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

int	get_pivot(t_stack *stack, size_t size)
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
		if (diff == 0 && (size % 2) == 1)
			break ;
		if (diff == -1 && (size % 2) == 0)
			break ;
		p = p->pre;
	}
	return (p->content);
}

#endif
