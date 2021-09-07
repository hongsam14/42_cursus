/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 01:41:47 by suhong            #+#    #+#             */
/*   Updated: 2021/09/06 20:52:06 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(struct timeval dtime)
{
	struct timeval	start_time;
	long			real_time;
	long			dreal_time;

	if (gettimeofday(&start_time, NULL) < 0)
		return (ERROR);
	real_time = start_time.tv_sec * 1000 + (start_time.tv_usec / 1000);
	dreal_time = dtime.tv_sec * 1000 + (dtime.tv_usec / 1000);
	return ((int)(real_time - dreal_time));
}

int	ft_usleep(int time)
{
	struct timeval	start_time;

	if (gettimeofday(&start_time, NULL) < 0)
		return (ERROR);
	while (get_time(start_time) < time)
		usleep(100);
	return (SUCCESS);
}

int	ft_printlog(int id, char *status)
{
	int		time;

	time = get_time(g_table.s_time);
	if (g_table.philo_dead == false
		&& g_table.complete_philos < g_table.philo_count)
	{
		printf("[%d] philo[%d] %s\n", time, id, status);
		return (SUCCESS);
	}
	return (ERROR);
}
