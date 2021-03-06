/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:23:13 by suhong            #+#    #+#             */
/*   Updated: 2021/05/13 23:47:31 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/common.h"

static void	print_stack(t_stack *stack)
{
	t_deck	*p;

	if (!stack_empty(stack))
	{
		p = stack->head;
		while (p != stack->tail)
		{
			ft_putnbr_fd(p->content, 1);
			ft_putstr_fd(", ", 1);
			p = p->next;
		}
		ft_putnbr_fd(p->content, 1);
	}
	ft_putchar_fd('\n', 1);
}

void	print_a_b_stack(t_stack *a, t_stack *b)
{
	ft_putstr_fd("------------------\n", 1);
	ft_putstr_fd("a:", 1);
	print_stack(a);
	ft_putstr_fd("b:", 1);
	print_stack(b);
	ft_putstr_fd("------------------\n", 1);
}

int	print_order(char *str, t_stack *a, t_stack *b)
{
	int	result;

	result = order(str, a, b);
	if (result == ERROR)
		return (ERROR);
	if (!result)
		return (0);
	step_count(1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	return (1);
}
