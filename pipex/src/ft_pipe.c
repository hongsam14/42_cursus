/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:29:05 by suhong            #+#    #+#             */
/*   Updated: 2021/07/13 15:29:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pipeing(int in, int out)
{
	if (in >= 0)
	{
		if (dup2(in, STDIN_FILENO) < 0)
			ft_syserror("dup2 error");
		close(in);
	}
	if (out >= 0)
	{
		if (dup2(out, STDOUT_FILENO) < 0)
			ft_syserror("dup2 error");
		close(out);
	}
}
