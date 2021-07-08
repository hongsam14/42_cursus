/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 06:02:19 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 11:11:05 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	run_subshell(t_built **built, t_list **env_list)
{
	int	order;
	int	**fd;
	int	size;

	order = 0;
	size = count_pipe(*built);
	fd = init_pipe(size);
	if (!fd)
		ft_error("malloc error");
	while (*built && order <= size)
	{
		g_mini.status = ft_subshell(*built, env_list, fd, order);
		*built = (*built)->next;
		order++;
	}
	free_pipe(&fd, size);
}

void	ft_shell(t_built *built, t_list **env_list)
{
	g_mini.status = SUCCESS;
	while (built && built->command)
	{
		ft_envswap(built->command, *env_list);
		if (built->next && built->next->command->str \
			&& built->next->command->str[0] == '|')
		{
			run_subshell(&built, env_list);
		}
		else if (built->command && built->command->str \
			&& built->command->str[0] == ';' && !built->command->next)
		{
			break ;
		}
		else if (!built->command->str)
			break ;
		else
		{
			g_mini.status = ft_execute(built, env_list);
			built = built->next;
		}
	}
}
