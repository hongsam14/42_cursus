/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 03:43:10 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 19:03:47 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	*init_philo(int philo_count)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * philo_count);
	if (!philo)
		return (0);
	while (i < philo_count)
	{
		philo[i].id = i;
		philo[i].eat_count = 0;
		philo[i].eating = false;
		if (pthread_mutex_init(&philo[i].fork, NULL))
			return (0);
		i++;
	}
	return (philo);
}

static void	init_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		if (i < table->philo_count - 1)
		{
			table->philos[i].l_fork = &table->philos[i].fork;
			table->philos[i].r_fork = &table->philos[i + 1].fork;
		}
		else
		{
			table->philos[i].l_fork = &table->philos[i].fork;
			table->philos[i].r_fork = &table->philos[0].fork;
		}
		i++;
	}
}

int	clean_table(t_table *table)
{
	int	i;

	i = 0;
	if (!table->philos)
		return (ERROR);
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&table->philos[i].fork);
		i++;
	}
	free(table->philos);
	return (ERROR);
}

int	init_table(t_table *table, int argc, char **argv)
{
	table->philo_count = atoi(argv[1]);
	table->life_time = atoi(argv[2]);
	table->eat_time = atoi(argv[3]);
	table->sleep_time = atoi(argv[4]);
	table->eat_count = -1;
	if (argc == 6)
		table->eat_count = atoi(argv[5]);
	table->philos = 0;
	table->philo_dead = false;
	table->complete_philos = 0;
	if (pthread_mutex_init(&table->mutex, NULL))
		return (ERROR);
	table->philos = init_philo(table->philo_count);
	if (!table->philos)
		return (ERROR);
	init_fork(table);
	if (gettimeofday(&table->s_time, NULL) < 0)
		return (ERROR);
	return (SUCCESS);
}
