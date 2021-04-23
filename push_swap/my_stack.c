/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:04:08 by suhong            #+#    #+#             */
/*   Updated: 2021/04/23 20:47:44 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_stack.h"

int	stack_init(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (ERROR);
	stack->deck = 0;
	stack->head = 0;
	stack->tail = 0;
	return (1);
}

void	stack_destroy(t_stack *stack)
{
}
