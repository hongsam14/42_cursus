/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:17:04 by suhong            #+#    #+#             */
/*   Updated: 2021/09/23 15:35:08 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct timeval	last_eat;
	int				eat_count;
	bool			eating;
}	t_philo;

typedef struct s_table
{
	int				philo_count;
	int				eat_time;
	int				sleep_time;
	int				life_time;
	int				eat_count;
	int				complete_philos;
	bool			philo_dead;
	struct timeval	s_time;
	t_philo			*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print_mutex;
}	t_table;

t_table					g_table;

void	*monitor(void *param);
void	*philosopher(void *param);

int		get_fork(t_philo *philo);
int		release_fork(t_philo *philo);

int		clean_table(t_table *table);
int		init_table(t_table *table, int argc, char **argv);

int		get_time(struct timeval dtime);
int		ft_usleep(int time);
int		ft_printlog(int id, char *status);
int		ft_error_in_thread(void);

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif
