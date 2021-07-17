/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:57:32 by suhong            #+#    #+#             */
/*   Updated: 2021/07/17 10:37:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_arg	arg;
	int		start;

	if (argc < 5)
		ft_syserror("less arguments");
	if (argc > 5)
		ft_syserror("too many arguments");
	arg = init_arg(argc, argv, envp);
	open_file(fd, argc, argv, &(arg.d_flag));
	arg = init_arg(argc, argv, envp);
	open_file(fd, argc, argv, &(arg.d_flag));
	start = 2;
	ft_pipex(start, arg, 0, fd);
	return (0);
}
