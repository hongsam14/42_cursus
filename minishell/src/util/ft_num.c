/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:19:58 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/04 23:01:25 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_num_len(int num)
{
	int		i;

	i = 1;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}
