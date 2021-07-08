/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:26 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 11:07:54 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtin(t_built *built, t_list **env_list)
{
	int		res;

	if (!built || !built->command)
		return (EXIT_FAILURE);
	if (ft_strncmp(built->command->str, "cd", 2))
		res = ft_cd(built, env_list);
	else if (ft_strncmp(built->command->str, "echo", 4))
		res = ft_echo(built);
	else if (ft_strncmp(built->command->str, "pwd", 3))
		res = ft_pwd();
	else if (ft_strncmp(built->command->str, "export", 6))
		res = ft_export(built, env_list);
	else if (ft_strncmp(built->command->str, "unset", 5))
		res = ft_unset(built, env_list);
	else if (ft_strncmp(built->command->str, "env", 3))
		res = ft_env(built, *env_list);
	else if (ft_strncmp(built->command->str, "exit", 4))
		res = ft_exit(built);
	else
		res = ft_execve(built, *env_list);
	return (res);
}
