/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:20:30 by suhong            #+#    #+#             */
/*   Updated: 2021/07/04 22:58:10 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_unset(t_built *built, t_list **env_list)
{
	t_list	*i;

	if (ft_guard_next(built, 1) == ERROR)
		return (ERROR);
	if (!ft_strncmp2(built->command->next->str, " ", 1))
		return (ERROR);
	i = built->command->next->next;
	while (i)
	{
		if (!ft_strncmp2(i->str, " ", 1))
			ft_delenv(env_list, i->str);
		i = i->next;
	}
	return (SUCCESS);
}
