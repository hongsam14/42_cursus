/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:11:19 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/04 22:58:58 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	**free_pipe(int ***pipe, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*pipe)[i]);
		i++;
	}
	free(*pipe);
	return (0);
}

int	count_pipe(t_built *built)
{
	int		i;
	t_built	*tmp;

	i = 0;
	tmp = built;
	if (tmp)
	{
		while (tmp->next && tmp->next->command->str[0] == '|')
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	**init_pipe(int size)
{
	int	j;
	int	**pip;

	j = 0;
	pip = (int **)malloc(sizeof(int *) * (size + 1));
	if (!pip)
		return (0);
	while (j < size)
	{
		pip[j] = (int *)malloc(sizeof(int) * 2);
		if (!pip[j] || pipe(pip[j]) == -1)
			return (free_pipe(&pip, j));
		j++;
	}
	pip[j] = 0;
	return (pip);
}

int	get_pipe_size(int **pipe)
{
	int	i;

	if (!pipe)
		return (0);
	i = 0;
	while (pipe[i])
		i++;
	return (i);
}
