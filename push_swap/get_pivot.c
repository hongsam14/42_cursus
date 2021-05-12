/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:22:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/12 15:22:55 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include <stdio.h>

#if 0
static long long	get_middle(t_stack *stack, int comp, size_t size)
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

static long long get_value(size_t size)
{
	long long	start;

	start = 0;
	if ((size % 2))
		start = 1;
	//return (2 * (size / 3) + start - (size / 3));
	return ((2 * size) / 3 - 1 - (size / 3));
}

void	get_pivot(t_stack *stack, size_t *size, int *p_l, int *p_h)
{
	t_deck	*p;
	long long	diff;
	size_t	full_size;
	size_t	i;

	diff = 0;
	i = 0;
	p = stack->tail;
	full_size = get_stack_size(*stack);
	if (*size > full_size)
		*size = full_size;
	while (i++ < *size)
	{
		diff = get_middle(stack, p->content, *size);
		printf("value: %lld diff:%lld\n", get_value(*size), diff);
		if (diff == get_value(*size))
			*p_h = p->content;
		if (diff == -1 * get_value(*size))
			*p_l = p->content;
		p = p->pre;
	}
}
#else

static int	*make_array(t_stack *stack, size_t *size)
{
	size_t	f_size;
	size_t	i;
	t_deck	*p;
	int	*tmp;
	
	i = 0;
	f_size = get_stack_size(*stack);
	if (*size > f_size)
		*size = f_size;
	tmp = (int *)malloc(sizeof(int) * (*size));
	if (!tmp)
		return (0);
	p = stack->tail;
	while (i < *size)
	{
		tmp[i] = p->content;
		i++;
		p = p->pre;
	}
	return (tmp);
}

static int	bubble_sort(int *array, size_t size)
{
	size_t	i_l;
	size_t	i_h;
	size_t	i;
	int	tmp;
	
	i = 0;
	while (i < size)
	{
		i_l = 0;
		i_h = 1;
		while (i_h < size)
		{
			if (array[i_l] > array[i_h])
			{
				tmp = array[i_l];
				array[i_l] = array[i_h];
				array[i_h] = tmp;
			}
			i_l++;
			i_h++;
		}
		i++;
	}
	return (1);
}

int	get_pivot(t_stack *stack, size_t *size, int *p_l, int *p_h)
{
	int	*array;
	size_t	i;

	i = 0;
	array = make_array(stack, size);
	if (!array)
		return (ERROR);
	bubble_sort(array, *size);
	*p_l = array[(*size) / 3];
	*p_h = array[((*size) * 2) / 3];
	free(array);
	return (1);
}

#endif
