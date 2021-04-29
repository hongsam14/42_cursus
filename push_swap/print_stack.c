/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:23:13 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 17:39:21 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/common.h"

void	print_stack(t_stack *stack)
{
	t_deck *p;

	if (stack_empty(stack))
		return ;
	p = stack->head;
	while (p != stack->tail)
	{
		ft_putnbr_fd(p->content, 1);
		write(1, ", ", 2);
		p = p->next;
	}
	ft_putnbr_fd(p->content, 1);
	write(1, "\n", 1);
}
