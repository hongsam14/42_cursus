/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:00:17 by suhong            #+#    #+#             */
/*   Updated: 2021/09/24 11:20:12 by suhong           ###   ########.fr       */
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
		if (pthread_detach(g_table.philos[i].tid) != SUCCESS)
			return (ERROR);
		i += 2;
	}
	return (SUCCESS);
}

static int	start_philos_2(void)
{
	int	i;

	usleep(10);
	i = 1;
	while (i < g_table.philo_count)
	{
		if (pthread_create(&g_table.philos[i].tid, NULL,
				philosopher, &g_table.philos[i]) != SUCCESS)
			return (ERROR);
		gettimeofday(&(g_table.philos[i].last_eat), NULL);
		if (pthread_detach(g_table.philos[i].tid) != SUCCESS)
			return (ERROR);
		i += 2;
	}
	return (SUCCESS);
}

static void	wait_philos(void)
{
	while (g_table.philo_dead == false
		&& g_table.complete_philos < g_table.philo_count)
	{
	}
}

static int	check_valid(int argc, char **argv)
{
	int		i;
	char	*c;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("not valid arg count\n");
		return (ERROR);
	}
	while (i < argc)
	{
		c = argv[i];
		while (*c)
		{
			if (!ft_isdigit(*c))
			{
				printf("arg not digit\n");
				return (ERROR);
			}
			c++;
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (check_valid(argc, argv) == ERROR)
		return (0);
	if (init_table(&g_table, argc, argv) == ERROR)
		return (clean_table(&g_table));
	if (start_philos() == ERROR || start_philos_2() == ERROR)
	{
		pthread_mutex_lock(&g_table.mutex);
		g_table.philo_dead = true;
		pthread_mutex_unlock(&g_table.mutex);
		return (clean_table(&g_table));
	}
	wait_philos();
	clean_table(&g_table);
	system("leaks philo");
	return (0);
}
