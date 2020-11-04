/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:43:43 by suhong            #+#    #+#             */
/*   Updated: 2020/11/04 13:15:28 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define FLAG_MINUS	1
# define FLAG_ZERO	2
# define FLAG_DOT	4
# define FLAG_STAR	8

typedef struct		s_format
{
	int				flag;
	int				width;
	int				decimal;
	char			specifier;
	struct s_format	*next;
}					t_format;

int					read_format(char *format, t_format *f_info);
int					ft_printf(const char *format, ...);
int					add_t_format(t_format **f_info, t_format *start);
int					del_t_format(t_format *f_start);

#endif
