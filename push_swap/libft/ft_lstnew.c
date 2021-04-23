/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 18:14:15 by suhong            #+#    #+#             */
/*   Updated: 2020/10/08 19:19:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*elmt;

	if ((elmt = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	elmt->content = content;
	elmt->next = 0;
	return (elmt);
}
