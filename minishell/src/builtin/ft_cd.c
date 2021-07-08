/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:06:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 05:27:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*ft_make_str(t_built *built, int *flag)
{
	char	*prev;
	char	*temp;
	t_list	*list;

	prev = 0;
	list = built->command->next->next;
	if (*(list->str) == '/')
	{
		prev = 0;
	}
	else if (*(list->str) == '~')
		(*flag) = 0;
	else
	{
		prev = getcwd(0, BUFFER_SIZE);
		temp = ft_strjoin(prev, "/");
		ft_free(prev);
		prev = temp;
	}
	return (prev);
}

static	int	change_pwd(t_list **env_list, char *dest, char *prev)
{
	int	res;

	res = chdir(dest);
	ft_add_env_list(env_list, ft_strndup("PWD", 3), getcwd(0, BUFFER_SIZE));
	if (res != SUCCESS)
	{
		res = ERROR;
		ft_perror(dest, 0);
	}
	ft_free(prev);
	ft_free(dest);
	return (res);
}

int	ft_cd(t_built *built, t_list **env_list)
{
	t_list	*list;
	char	*prev;
	char	*dest;
	int		flag;
	int		res;

	flag = 1;
	if (built->command->next && built->command->next->next)
		prev = ft_make_str(built, &flag);
	else
		flag = 0;
	if (flag)
	{
		list = built->command->next->next;
		dest = ft_strjoin(prev, list->str);
	}
	else
	{
		prev = ft_getenv(*env_list, "HOME", 4);
		dest = ft_strndup(prev, ft_strlen(prev));
	}
	res = change_pwd(env_list, dest, prev);
	return (res);
}
