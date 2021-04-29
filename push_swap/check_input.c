/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:41:25 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 13:56:50 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/checker.h"

static int	two_word(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "sa", 2))
		return (swap_order(a));
	if (!ft_strncmp(str, "sb", 2))
		return (swap_order(b));
	if (!ft_strncmp(str, "ss", 2))
		return (dble_order(a, b, swap_order));
	if (!ft_strncmp(str, "pa", 2))
		return (push_order(b, a));
	if (!ft_strncmp(str, "pb", 2))
		return (push_order(a, b));
	if (!ft_strncmp(str, "ra", 2))
		return (rotate_order(a));
	if (!ft_strncmp(str, "rb", 2))
		return (rotate_order(b));
	if (!ft_strncmp(str, "rr", 2))
		return (dble_order(a, b, rotate_order));
	return (ERROR);
}

static int	three_word(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "rra", 3))
		return (rev_rotate_order(a));
	if (!ft_strncmp(str, "rrb", 3))
		return (rev_rotate_order(b));
	if (!ft_strncmp(str, "rrr", 3))
		return (dble_order(a, b, rev_rotate_order));
	return (ERROR);
}

static int	check_input(char *str, t_stack *a, t_stack *b)
{
	int		size;

	size = ft_strlen(str);
	if (size == 0)
		return (0);
	if (size == 2)
		return (two_word(str, a, b));
	if (size == 3)
		return (three_word(str, a, b));
	free(str);
	return (ERROR);
}

int			get_input_str(t_stack *a, t_stack *b)
{
	int		result;
	char	*str;

	result = get_next_line(0, &str);
	while (result >= 0)
	{
		if (check_input(str, a, b) == ERROR)
			return (ERROR);
		free(str);
		if (!result)
			break ;
		result = get_next_line(0, &str);
	}
	if (result < 0)
		return (ERROR);
	return (OK);
}
