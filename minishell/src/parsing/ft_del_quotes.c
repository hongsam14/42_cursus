/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:59:46 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 04:16:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	meet_q_blank_token(char **str)
{
	if (ft_strncmp(*str, "\"\"", 2) || ft_strncmp(*str, "\'\'", 2))
	{
		ft_free(*str);
		*str = ft_strndup("", 1);
		return (1);
	}
	return (0);
}

void	ft_del_quotes(t_list *list)
{
	int			i;
	char		c;
	int			temp;

	temp = 0;
	while (list)
	{
		i = 0;
		while (list->str && list->str[i])
		{
			if (meet_q_blank_token(&(list->str)))
				break ;
			else if (ft_strchr("\'\"", list->str[i]))
			{
				c = list->str[i];
				list->str = ft_del_char(&list->str, i + 1);
				temp = ft_strchr(&list->str[i], c) - list->str;
				list->str = ft_del_char(&list->str, temp + 1);
				i = temp;
			}
			else
				i++;
		}
		list = list->next;
	}
}
