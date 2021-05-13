/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:22:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/12 16:19:00 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

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
