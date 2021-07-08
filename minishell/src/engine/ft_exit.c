/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:38:11 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 11:07:41 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	ll_cut(long long n)
{
	return ((int)(n % 256));
}

int	ft_exit(t_built *built)
{
	t_list	*list;

	list = built->command;
	if (!list->next)
	{
		ft_putstr_fd("exit", STDERR, 0);
		exit(g_mini.status);
	}
	list = list->next;
	if (list->next && !list->next->next)
	{
		if (ft_is_num(list->next->str) == SUCCESS)
			exit(ll_cut(ft_atoi(list->next->str)));
		else
		{
			ft_putstr_fd("minish: exit: ", STDERR, "\x1b[31m");
			ft_putstr_fd(list->next->str, STDERR, "\x1b[31m");
			ft_putstr_fd(": numeric argument required\n", STDERR, "\x1b[31m");
		}
		exit(255);
	}
	else
		ft_putstr_fd("exit\nminish: exit: too many arguments\n", \
			STDERR, "\x1b[31m" );
	return (EXIT_FAILURE);
}

int	ft_close(int fd)
{
	if (fd > 1)
		return (close(fd));
	return (1);
}
