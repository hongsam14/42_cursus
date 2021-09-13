/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 03:43:10 by suhong            #+#    #+#             */
/*   Updated: 2021/09/13 14:46:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_mutex_destroy(&g_table.mutex);
	pthread_mutex_destroy(&g_table.print_mutex);
	return (SUCCESS);
}

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

static int	check_arg(t_table *table, int argc, char **argv)
{
	table->philo_count = ft_atoi(argv[1]);
	if (table->philo_count <= 0)
		return (ERROR);
	table->life_time = ft_atoi(argv[2]);
	if (table->life_time <= 0)
		return (ERROR);
	table->eat_time = ft_atoi(argv[3]);
	if (table->eat_time <= 0)
		return (ERROR);
	table->sleep_time = ft_atoi(argv[4]);
	if (table->sleep_time <= 0)
		return (ERROR);
	table->eat_count = -1;
	if (argc == 6)
	{
		table->eat_count = ft_atoi(argv[5]);
		if (table->eat_count < 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (check_arg(table, argc, argv) == ERROR)
	{
		printf("negative input value\n");
		return (ERROR);
	}
	table->philos = 0;
	table->philo_dead = false;
	table->complete_philos = 0;
	if (pthread_mutex_init(&table->mutex, NULL))
		return (ERROR);
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (ERROR);
	table->philos = init_philo(table->philo_count);
	if (!table->philos)
		return (ERROR);
	init_fork(table);
	if (gettimeofday(&table->s_time, NULL) < 0)
		return (ERROR);
	return (SUCCESS);
}
