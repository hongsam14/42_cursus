/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:27:49 by suhong            #+#    #+#             */
/*   Updated: 2021/07/17 10:28:10 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(int index, t_arg arg, int pip_in, int *prompt_fd)
{
	char	**argv;
	int		res;
	int		pip[2];

	res = 0;
	argv = parse_cmd(arg.argv[index]);
	if (!argv)
		return (ERROR);
	if (pipe(pip) < 0)
		ft_syserror("pipe error");
	if (index == arg.argc - 2)
	{
		res = ft_exec(pip_in, prompt_fd[1], argv, arg.envp);
		ft_free2(argv);
		return (res);
	}
	else if (index == 2 + arg.d_flag)
		res = ft_exec(prompt_fd[0], pip[1], argv, arg.envp);
	else
		res = ft_exec(pip_in, pip[1], argv, arg.envp);
	ft_free2(argv);
	return (ft_pipex(index + 1, arg, pip[0], prompt_fd));
}
