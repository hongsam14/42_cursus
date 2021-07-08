/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:51:53 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 03:20:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_list	*del_pipe_col(t_built *built)
{
	t_built	*temp;

	if (!built->command || !built->command->next)
	{
		if (ft_strchr2("|;", built->command->str[0]) && !built->command->next)
		{
			if (built->command->id)
				return (built->command);
			temp = built->next;
			if (temp)
				return (temp->command);
			else
				return (0);
		}
		return (built->command);
	}
	if (ft_strchr2("|;", built->command->str[0]))
		return (built->command->next->next);
	return (built->command);
}

static void	ft_open_execute(int *temp_p, int *fd)
{
	temp_p[0] = dup(STDIN);
	temp_p[1] = dup(STDOUT);
	fd[0] = STDIN;
	fd[1] = STDOUT;
}

static void	ft_close_execute(int *temp_p, int *fd)
{
	ft_close(fd[0]);
	ft_close(fd[1]);
	dup2(temp_p[1], STDOUT);
	dup2(temp_p[0], STDIN);
	g_mini.pip[0] = dup(STDIN);
	g_mini.pip[1] = dup(STDOUT);
}

static int	ft_execute2(t_built *built, t_list **env_list, int *fd)
{
	int	res;

	if (!built || !(built->command) || !(built->command->str))
		return (EXIT_SUCCESS);
	if (built->next)
	{
		res = ft_execute2(built->next, env_list, fd);
		if (res == ERROR)
			return (res);
	}
	if (ft_strncmp(built->command->str, ">", 1))
		res = ft_redirect(built, "TRUNC", fd);
	else if (ft_strncmp(built->command->str, ">>", 2))
		res = ft_redirect(built, "APPEND", fd);
	else if (ft_strncmp(built->command->str, "<", 1))
		res = ft_redirect2(built);
	else if (ft_strncmp(built->command->str, "<<", 2))
		res = ft_redirect3(built, fd);
	else
		res = ft_builtin(built, env_list);
	return (res);
}

int	ft_execute(t_built *built, t_list **env_list)
{
	t_list	*list;
	int		fd[2];
	int		temp_p[2];
	int		status;
	t_built	*temp;

	if (!built || !built->command || !built->command->str)
		return (EXIT_SUCCESS);
	ft_open_execute(temp_p, fd);
	list = del_pipe_col(built);
	if (!(list))
		return (REDIRECTION_ERROR);
	temp = ft_builtndup(list);
	if (!ft_strchr2("><", temp->command->str[0]))
		ft_split_built(temp, "><");
	ft_del_lastblank(temp);
	g_mini.pip[0] = dup(STDIN);
	g_mini.pip[1] = dup(STDOUT);
	status = ft_execute2(temp, env_list, fd);
	ft_close_execute(temp_p, fd);
	ft_builtclear(&temp);
	return (status);
}
