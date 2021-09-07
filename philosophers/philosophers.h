/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:17:04 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 19:06:53 by suhong           ###   ########.fr       */
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

typedef struct s_node
{
	void			*cont;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node			head;
	t_node			*tail;
	int				size;
	pthread_mutex_t	mutex;
}	t_queue;

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_philo	*l_philo;
	struct s_philo	*r_philo;
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
}	t_table;

t_table					g_table;
t_queue					g_queue;

int		init_queue(t_queue *queue);
int		del_queue(t_queue *queue);
int		inqueue(t_queue *queue, void *cont);
void	*dequeue(t_queue *queue);
void	*get_head_cont(t_queue *queue);

void	*monitor(void *param);
void	*philosopher(void *param);

int		get_fork(t_philo *philo);
int		release_fork(t_philo *philo);

int		clean_table(t_table *table);
int		init_table(t_table *table, int argc, char **argv);

int		get_time(struct timeval dtime);
int		ft_usleep(int time);
int		ft_printlog(int id, char *status);

#endif
