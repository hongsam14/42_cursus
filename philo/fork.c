/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:03:38 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 17:22:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork))
		return (ERROR);
	if (pthread_mutex_lock(philo->r_fork))
		return (ERROR);
	if (ft_printlog(philo->id, "has taken fork") == ERROR)
		return (SUCCESS);
	return (SUCCESS);
}

int	release_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->l_fork))
		return (ERROR);
	if (pthread_mutex_unlock(philo->r_fork))
		return (ERROR);
	return (SUCCESS);
}
