/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:23:13 by suhong            #+#    #+#             */
/*   Updated: 2021/04/30 14:18:09 by suhong           ###   ########.fr       */
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
		ft_putstr_fd(", ", 1);
		p = p->next;
	}
	ft_putnbr_fd(p->content, 1);
	ft_putchar_fd('\n', 1);
}

void	print_a_b_stack(t_stack *a, t_stack *b)
{
	ft_putstr_fd("------------------", 1);
	ft_putstr_fd("a:", 1);
	print_stack(a);
	ft_putstr_fd("b:", 1);
	print_stack(b);
	ft_putstr_fd("------------------", 1);
}
