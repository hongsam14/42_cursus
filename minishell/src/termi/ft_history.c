/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:10:56 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 09:36:27 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termi.h"

void	ft_add_history(void)
{
	t_list	*temp;
	char	*str;

	ft_putchar_fd('\n', STDERR, 0);
	if (!g_mini.line)
		return ;
	str = ft_strndup(g_mini.line, ft_strlen(g_mini.line));
	temp = ft_listnew2(str, 0);
	ft_listadd_front(&g_mini.head, &temp);
	g_mini.history = temp;
}

void	ft_up_arrow(int *cursor, int *len)
{
	if (!g_mini.history)
		return ;
	tputs(tgetstr("dl", NULL), 1, ft_putchar_tc);
	draw2();
	ft_putstr_fd(g_mini.history->str, STDOUT, 0);
	ft_free(g_mini.line);
	g_mini.line = ft_strndup(g_mini.history->str, \
							ft_strlen(g_mini.history->str));
	g_mini.history = g_mini.history->next;
	(*len) = ft_strlen(g_mini.line);
	(*cursor) = (*len);
}

void	ft_down_arrow(int *cursor, int *len)
{
	if (!g_mini.history)
		return ;
	tputs(tgetstr("dl", NULL), 1, ft_putchar_tc);
	draw2();
	ft_putstr_fd(g_mini.history->str, STDOUT, 0);
	ft_free(g_mini.line);
	g_mini.line = ft_strndup(g_mini.history->str, \
				ft_strlen(g_mini.history->str));
	g_mini.history = g_mini.history->prev;
	(*len) = ft_strlen(g_mini.line);
	(*cursor) = (*len);
}
