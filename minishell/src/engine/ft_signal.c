/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
/*   Updated: 2021/09/09 15:54:03 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		kill(g_mini.pid, SIGINT);
		// signal(SIGINT, proc_signal_handler);
	}
	if (signo == SIGQUIT)
	{
		kill(g_mini.pid, SIGQUIT);
		printf("Quit: %d\n", signo);
		// signal(SIGQUIT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	g_mini.signal = signo;
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1, 0);
		ft_init_get_line(&g_mini.cursor, &g_mini.len);
		draw2();
		// signal(SIGINT, signal_handler);
	}
	if (signo == SIGQUIT)
	{
		// signal(SIGQUIT, signal_handler);
	}
}

void	ft_prompt_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	ft_proc_signal(void)
{
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, proc_signal_handler);
}

void	ctrl_d_checker(int c)
{
	if (c == 4)
	{
		if (g_mini.line)
		{
			if (!*g_mini.line)
			{
				ft_free(g_mini.line);
				ft_putstr_fd("exit", 2, 0);
				exit(0);
			}
		}
	}
}
