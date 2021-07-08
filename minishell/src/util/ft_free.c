/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:06 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 19:41:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_free(void *memory)
{
	if (memory)
	{
		free(memory);
		memory = 0;
	}
}

void	ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
		{
			ft_free(s[i]);
		}
	}
	ft_free(s);
}
