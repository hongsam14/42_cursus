/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:15:12 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 05:15:13 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "head.h"

void		ft_perror(char *filename, char *message);
void		ft_syntaxerror(char type);
void		ft_error(char *str);
int			ft_execute(t_built *built, t_list **env_list);
int			ft_execve(t_built *built, t_list *env_list);
int			ft_exit(t_built *built);
int			ft_close(int fd);
int			ft_guard_next(t_built *built, int n);
int			ft_status_control(int status);
void		ft_parent(pid_t pid, int *status);
int			**free_pipe(int ***pipe, int size);
int			count_pipe(t_built *built);
int			**init_pipe(int size);
int			get_pipe_size(int **pipe);
int			ft_redirect(t_built *built, char *type, int *fd);
int			ft_redirect2(t_built *built);
int			ft_redirect3(t_built *built, int *fd);
void		ft_shell(t_built *built, t_list **env_list);
void		proc_signal_handler(int signo);
void		signal_handler(int signo);
void		ft_prompt_signal(void);
void		ft_proc_signal(void);
void		ctrl_d_checker(int c);
int			ft_subshell(t_built *built, t_list **env_list, int **fd, int order);

#endif
