/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:06 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 22:58:49 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	ft_guard_next(t_built *built, int n)
{
	t_list	*temp;

	temp = built->command;
	while (n--)
	{
		if (temp->next)
			temp = temp->next;
		else
			return (ERROR);
	}
	return (SUCCESS);
}
