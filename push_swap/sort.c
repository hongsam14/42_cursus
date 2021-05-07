/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:22:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/07 21:48:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

static int	*make_array(t_stack *stack, size_t *size)
{
	int		*tmp;
	int		i;
	t_deck	*p;

	*size = get_stack_size(*stack);
	if (*size < 3)
		return (0);
	tmp = (int *)malloc(sizeof(int) * (*size));
	if (!tmp)
		return (0);
	p = stack->head;
	i = 0;
	tmp[i++] = p->content;
	while (p != stack->head)
	{
		tmp[i++] = p->content;
		p = p->next;
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
	while (low < high)
	{
		while (array[low] < pivot && low <= tail)
			low++;
		while (array[high] > pivot && high > head)
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
		printf("pivot:%d\n", pivot);
		quick_sort(array, head, pivot - 1);
		quick_sort(array, pivot + 1, tail);
	}
}

int	get_pivot(t_stack *stack, int *pivot)
{
	int				*tmp;
	size_t			size;
	unsigned int	i;

	i = 0;
	tmp = make_array(stack, &size);
	if (!tmp)
		return (0);
	quick_sort(tmp, 0, size - 1);
	while (i < size)
	{
		printf("%d", tmp[i]);
		i++;
	}
	*pivot = i;
	printf("\n");
	return (1);
}
