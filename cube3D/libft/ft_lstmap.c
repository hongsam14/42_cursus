/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong.student@42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:46:51 by suhong            #+#    #+#             */
/*   Updated: 2020/10/08 18:55:11 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (lst == 0 || f == 0)
		return (0);
	if ((tmp = ft_lstnew(f(lst->content))) == 0)
		return (0);
	start = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if ((tmp->next = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		tmp = tmp->next;
	}
	return (start);
}
