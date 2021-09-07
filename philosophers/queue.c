/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:34:07 by suhong            #+#    #+#             */
/*   Updated: 2021/09/07 19:04:16 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_queue(t_queue *queue)
{
	queue->tail = &queue->head;
	queue->head.cont = 0;
	queue->head.next = 0;
	queue->size = 0;
	if (pthread_mutex_init(&queue->mutex, NULL))
		return (ERROR);
	return (SUCCESS);
}

int	del_queue(t_queue *queue)
{
	t_node	*n;
	t_node	*tmp;

	n = queue->head.next;
	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
	queue->tail = 0;
	queue->size = 0;
	pthread_mutex_destroy(&queue->mutex);
	return (ERROR);
}

int	inqueue(t_queue *queue, void *cont)
{
	t_node	*add;

	pthread_mutex_lock(&queue->mutex);
	add = (t_node *)malloc(sizeof(t_node));
	if (!add)
	{
		pthread_mutex_unlock(&queue->mutex);
		return (ERROR);
	}
	add->cont = cont;
	add->next = 0;
	queue->tail->next = add;
	queue->tail = add;
	queue->size++;
	pthread_mutex_unlock(&queue->mutex);
	return (SUCCESS);
}

void	*dequeue(t_queue *queue)
{
	void	*ret;
	t_node	*tmp;

	pthread_mutex_lock(&queue->mutex);
	if (!queue->head.next)
	{
		pthread_mutex_unlock(&queue->mutex);
		return (0);
	}
	ret = queue->head.next->cont;
	tmp = queue->head.next->next;
	free(queue->head.next);
	queue->head.next = tmp;
	if (queue->size > 0)
		queue->size--;
	pthread_mutex_unlock(&queue->mutex);
	return (ret);
}

void	*get_head_cont(t_queue *queue)
{
	if (queue->head.next)
		return (queue->head.next->cont);
	return (0);
}
