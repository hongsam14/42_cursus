/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:23:24 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 22:58:07 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(0, BUFFER_SIZE);
	ft_putstr_fd(cwd, 1, 0);
	ft_putchar_fd('\n', 1, 0);
	ft_free(cwd);
	return (SUCCESS);
}
