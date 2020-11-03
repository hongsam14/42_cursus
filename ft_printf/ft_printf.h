/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:43:43 by suhong            #+#    #+#             */
/*   Updated: 2020/11/03 16:55:57 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define flag_minus	1
# define flag_zero	2
# define flag_dot	4
# define flag_star	8

typedef struct	s_format
{
	int		flag;
	int		width;
	int		decimal;
	char		specifier;
	t_format	*next;
}			t_format;

int			read_format(char **format, t_format *f_info);
int			ft_printf(const char *format, ...);

#endif
