/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:27:43 by suhong            #+#    #+#             */
/*   Updated: 2021/07/21 00:18:58 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(int *fd, int argc, char **argv, int *d_flag)
{
	char	*tmp;

	tmp = 0;
	fd[0] = STDIN_FILENO;
	if (argv[1] && *(argv[1]))
	{
		if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
			*d_flag = 1;
		else
			fd[0] = open(argv[1], O_RDONLY, S_IRWXU);
	}
	fd[1] = STDOUT_FILENO;
	if (argv[argc - 1] && *(argv[argc - 1]))
	{
		if (*d_flag)
			fd[1] = open(argv[argc - 1], \
				O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
		else
			fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	}
}

void	ft_free2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

t_arg	init_arg(int argc, char **argv, char **envp)
{
	t_arg	tmp;

	tmp.argc = argc;
	tmp.argv = argv;
	tmp.envp = envp;
	tmp.d_flag = 0;
	return (tmp);
}

void	check_eof(char *str, int in_fd, int pip_fd)
{
	char	*line;

	line = 0;
	while (get_next_line(in_fd, &line) >= 0)
	{
		if (!ft_strncmp(line, str, ft_strlen(line)))
		{
			close(pip_fd);
			free(line);
			break ;
		}
		ft_putstr_fd(line, pip_fd);
		ft_putstr_fd("\n", pip_fd);
		free(line);
	}
}
