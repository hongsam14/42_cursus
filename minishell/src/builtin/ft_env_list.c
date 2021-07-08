/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:35 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 10:27:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_list	*ft_init_env_list(char **envp)
{
	size_t	i;
	char	**env_str;
	t_list	*tmp;
	t_list	*list;

	list = 0;
	i = 0;
	while (envp[i])
	{
		env_str = ft_split(envp[i], '=');
		if (!env_str)
			ft_error("malloc failed");
		if (!env_str[1])
			env_str[1] = ft_strndup("", 0);
		tmp = ft_listnew2(env_str[1], env_str[0]);
		ft_listadd_tail(&list, &tmp);
		ft_free(env_str);
		i++;
	}
	return (list);
}

int	ft_add_env_list(t_list **list, char *id, char *str)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!id)
		return (ERROR);
	if (ft_isdigit(id[0]) || id[0] == '%')
		return (ERROR);
	while (id[i])
	{
		if (ft_isenv(id[i]))
			return (ERROR);
		i++;
	}
	ft_delenv(list, id);
	tmp = ft_listnew2(str, id);
	ft_listadd_tail(list, &tmp);
	return (SUCCESS);
}

void	ft_delenv(t_list **list, char *str)
{
	t_list	*i;
	t_list	*tmp;
	t_list	*prev;

	i = *list;
	while (i)
	{
		tmp = i->next;
		if (ft_strncmp(i->id, str, ft_strlen(str)))
		{
			ft_listdelone(&i);
		}
		else
			prev = i;
		i = tmp;
	}
	while (prev->prev)
		prev = prev->prev;
	*list = prev;
}

void	ft_show_env_list(t_list *list, char *str)
{
	while (list)
	{
		if (str)
			ft_putstr_fd(str, 1, 0);
		if (list->str)
		{
			ft_putstr_fd(list->id, 1, 0);
			write(1, "=", 1);
			ft_putstr_fd(list->str, 1, 0);
			write(1, "\n", 1);
		}
		list = list->next;
	}
}

void	ft_show_env_list_2(t_list *list, char *str)
{
	while (list)
	{
		if (str)
			ft_putstr_fd(str, 1, 0);
		ft_putstr_fd(list->id, 1, 0);
		if (list->str)
		{
			write(1, "=", 1);
			write(1, "\"", 1);
			ft_putstr_fd(list->str, 1, 0);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		list = list->next;
	}
}
