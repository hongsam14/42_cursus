/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:21:51 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 18:08:39 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eat(t_philo *philo)
{
	get_fork(philo);
	if (gettimeofday(&philo->last_eat, NULL) < 0)
		return (ERROR);
	philo->eating = true;
	if (ft_printlog(philo->id, "is eatting") == ERROR)
		return (SUCCESS);
	ft_usleep(g_table.eat_time);
	release_fork(philo);
	philo->eat_count++;
	if (philo->eat_count == g_table.eat_count)
	{
		pthread_mutex_lock(&g_table.mutex);
		g_table.complete_philos++;
		pthread_mutex_unlock(&g_table.mutex);
	}
	return (SUCCESS);
}

static int	ft_sleep(t_philo *philo)
{
	if (ft_printlog(philo->id, "is sleeping") == ERROR)
		return (SUCCESS);
	ft_usleep(g_table.sleep_time);
	return (SUCCESS);
}

static int	ft_think(t_philo *philo)
{
	if (ft_printlog(philo->id, "is thinking") == ERROR)
		return (SUCCESS);
	return (SUCCESS);
}

void	*monitor(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!pthread_mutex_lock(&g_table.mutex) && g_table.philo_dead == false)
	{
		if (get_time(philo->last_eat) > g_table.life_time)
		{
			g_table.philo_dead = true;
			printf("[%d] philo[%d] died\n",
				get_time(g_table.s_time), philo->id);
		}
		pthread_mutex_unlock(&g_table.mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&g_table.mutex);
	return (0);
}

void	*philosopher(void *param)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)param;
	if (pthread_create(&tid, NULL, monitor, philo) != SUCCESS)
		return (0);
	pthread_detach(tid);
	while (g_table.philo_dead == false
		&& g_table.complete_philos < g_table.philo_count)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}
