/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:15:55 by suhong            #+#    #+#             */
/*   Updated: 2021/07/17 10:27:01 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <limits.h>
# include <string.h>

# define SUCCESS	0
# define ERROR		1
# define BUFFER_SIZE 30

typedef struct s_arg
{
	int		argc;
	char	**argv;
	char	**envp;
	int		d_flag;
}		t_arg;

void	open_file(int *fd, int argc, char **argv, int *d_flag);
void	ft_free2(char **str);
t_arg	init_arg(int argc, char **argv, char **envp);
void	check_eof(char *str, int in_fd, int pip_fd);

int		get_next_line(int fd, char **line);

void	ft_perror(char *filename, char *message);
void	ft_syserror(char *message);

void	do_pipeing(int in, int out);

char	**ft_token_split(char *str, char c);
char	**parse_cmd(char *str);

int		ft_exec(int pip_in, int pip_out, char **argv, char **envp);

int		ft_pipex(int index, t_arg arg, int pip_in, int *prompt_fd);

#endif
