/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:43:43 by suhong            #+#    #+#             */
/*   Updated: 2020/11/16 11:39:54 by suhong           ###   ########.fr       */
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

typedef struct		s_format
{
	int				flag : 7;
	int				width;
	int				precision;
	char			specifier;
	struct s_format	*next;
}					t_format;

int					ft_printf(const char *format, ...);
int					read_format(char *format, t_format **f_info
		, va_list *v_lst);
int					print_format(char *format, t_format *f_info
		, va_list *v_lst);
int					init_t_format(t_format **new_f);
int					del_t_format(t_format **f_info);
int					print_space_by_flag(t_format f_info);
void				add_back_t_format(t_format **f_info, t_format *new_t);
char				change_2_hex(int value, int capital);

int					read_c_type(char src, t_format f_info);
int					read_s_type(char *src, t_format f_info);
int					read_percent_type(t_format f_info);
int					read_p_type(void *src, t_format f_info);
int					read_di_type(int src, t_format f_info);
int					read_ux_type(unsigned int src, t_format f_info);

#endif
