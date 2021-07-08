/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:15:41 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 09:41:50 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_getchar(int *cursor, int *len, int n)
{
	char	c;

	tputs(tgetstr("im", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("ic", NULL), 1, ft_putchar_tc);
	(*cursor)++;
	(*len)++;
	c = (char)n;
	ft_putchar_fd(c, STDERR, "\x1b[34m");
	g_mini.line = ft_add_char(&g_mini.line, c, (*cursor));
	tputs(tgetstr("ip", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("ei", NULL), 1, ft_putchar_tc);
}

static int	ft_printchar(int *cursor, int *len, int n)
{
	int		i;
	int		c;

	i = 0;
	c = n;
	while (i < 4 && c)
	{
		c = n >> (8 * i);
		c = (char)c;
		if (ft_isprint(c))
			ft_getchar(cursor, len, c);
		else if (c == '\n' || c == 4)
		{
			ft_add_history();
			return (SUCCESS);
		}
		i++;
	}
	return (ERROR);
}

void	ft_init_get_line(int *cursor, int *len)
{
	if (!ft_malloc(&g_mini.line, sizeof(char)))
		return ;
	g_mini.line[0] = 0;
	(*cursor) = 0;
	(*len) = 0;
}

void	ft_get_line(void)
{
	int		n;

	ft_init_get_line(&g_mini.cursor, &g_mini.len);
	n = 0;
	while (read(STDIN, &n, sizeof(int)) > 0)
	{
		if (n == LEFT_ARROW && g_mini.cursor > 0)
			ft_left_arrow(&g_mini.cursor);
		else if (n == RIGHT_ARROW && g_mini.cursor < g_mini.len)
			ft_right_arrow(&g_mini.cursor);
		else if (n == BACKSPACE && g_mini.cursor > 0)
			ft_backspace(&g_mini.cursor, &g_mini.len);
		else if (n == UP_ARROW)
			ft_up_arrow(&g_mini.cursor, &g_mini.len);
		else if (n == DOWN_ARROW)
			ft_down_arrow(&g_mini.cursor, &g_mini.len);
		else if (ft_isprint(n) || n == '\n')
		{
			if (ft_printchar(&g_mini.cursor, &g_mini.len, n) == SUCCESS)
				return ;
		}
		ctrl_d_checker(n);
		n = 0;
	}
}
