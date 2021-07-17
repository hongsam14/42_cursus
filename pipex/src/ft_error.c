/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:29:43 by suhong            #+#    #+#             */
/*   Updated: 2021/07/14 15:54:48 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *filename, char *message)
{
	ft_putstr_fd("pipex : ", STDERR_FILENO);
	if (filename)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		write(2, ": ", 2);
	}
	if (message)
	{
		ft_putstr_fd(message, STDERR_FILENO);
		write(2, "\n", 1);
	}
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		write(2, "\n", 1);
	}
}

void	ft_syserror(char *message)
{
	ft_perror(0, message);
	exit(ERROR);
}
