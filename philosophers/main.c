/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:00:17 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 19:01:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	start_philos(void)
{
	int	i;

	i = 0;
	while (i < g_table.philo_count)
	{
		if (pthread_create(&g_table.philos[i].tid, NULL,
				philosopher, &g_table.philos[i]) != SUCCESS)
			return (ERROR);
		gettimeofday(&(g_table.philos[i].last_eat), NULL);
		i += 2;
	}
	usleep(10);
	i = 1;
	while (i < g_table.philo_count)
	{
		if (pthread_create(&g_table.philos[i].tid, NULL,
				philosopher, &g_table.philos[i]) != SUCCESS)
			return (ERROR);
		gettimeofday(&(g_table.philos[i].last_eat), NULL);
		i += 2;
	}
	return (SUCCESS);
}

static int	join_philos(void)
{
	int	i;

	i = 0;
	while (i < g_table.philo_count)
	{
		if (pthread_detach(g_table.philos[i].tid) != SUCCESS)
			return (ERROR);
		usleep(50);
		i++;
	}
	while (g_table.philo_dead == false
		&& g_table.complete_philos < g_table.philo_count)
	{
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ERROR);
	if (init_table(&g_table, argc, argv) == ERROR)
		return (ERROR);
	if (init_queue(&g_queue) == ERROR)
		return (del_queue(&g_queue) | clean_table(&g_table));
	if (start_philos() == ERROR)
		return (del_queue(&g_queue) | clean_table(&g_table));
	if (join_philos() == ERROR)
		return (del_queue(&g_queue) | clean_table(&g_table));
	clean_table(&g_table);
	del_queue(&g_queue);
	return (0);
}
