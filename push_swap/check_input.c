/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:24:57 by suhong            #+#    #+#             */
/*   Updated: 2021/05/05 16:27:34 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/checker.h"

int	get_input_str(t_stack *a, t_stack *b)
{
	int	result;
	char	*str;

	result = get_next_line(0, &str);
	while (result >= 0)
	{
		if (order(str, a, b) == ERROR)
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
