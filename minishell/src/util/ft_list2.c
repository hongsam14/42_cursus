/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 02:02:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_listclear(t_list **list)
{
	t_list		*temp;

	if (!list || !(*list))
		return ;
	temp = (*list);
	while ((*list) && list)
	{
		temp = temp->next;
		ft_listdelone(list);
		*list = temp;
	}
	*list = 0;
}

char	**ft_env_listtochar(t_list *list)
{
	char	**res;
	char	*str;
	int		i;
	int		n;

	n = ft_list_cnt(list);
	if (!ft_malloc(&res, sizeof(char *) * (n + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		str = ft_strjoin(list->id, "=");
		res[i] = ft_strjoin(str, list->str);
		ft_free(str);
		list = list->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_listtochar(t_list *list)
{
	char	**res;
	int		i;
	int		n;
	t_list	*temp;

	n = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		n++;
	}
	if (!ft_malloc(&res, sizeof(char *) * (n + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		res[i] = ft_strndup(list->str, ft_strlen(list->str));
		list = list->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

void	ft_listadd_front(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*new)->next = (*new);
		(*new)->prev = (*new);
		(*list) = (*new);
	}
	else
	{
		if ((*list)->prev)
			(*list)->prev->next = (*new);
		(*new)->prev = (*list)->prev;
		(*list)->prev = (*new);
		(*new)->next = *list;
		(*list) = (*new);
	}
}

t_list	*ft_listdup(t_list *list)
{
	t_list	*copy;
	t_list	*dup;
	t_list	*add;

	copy = 0;
	dup = list;
	while (dup)
	{
		add = 0;
		if (dup->str)
			add = ft_listnew2(ft_strndup(dup->str, ft_strlen(dup->str)), \
				ft_strndup(dup->id, ft_strlen(dup->id)));
		else
			add = ft_listnew2(0, ft_strndup(dup->id, ft_strlen(dup->id)));
		if (!add)
			ft_error("malloc error");
		ft_listadd_tail(&copy, &add);
		dup = dup->next;
	}
	return (copy);
}
