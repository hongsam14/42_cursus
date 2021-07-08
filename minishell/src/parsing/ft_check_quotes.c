/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 03:56:08 by hongseong         #+#    #+#             */
/*   Updated: 2021/07/06 04:53:23 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
int	ft_check_quotes(char c, int *q_tmp)
{
	static char	tmp = 0;

	if (!c || c == tmp)
	{
		tmp = 0;
	}
	else if (ft_strchr("\"\'", c) && !tmp)
	{
		tmp = c;
	}
	if (tmp && q_tmp)
		*q_tmp = tmp;
	return (tmp);
}
