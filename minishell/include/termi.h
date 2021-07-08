/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:15:19 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 05:15:20 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMI_H
# define TERMI_H
# include "head.h"

int			ft_putchar_tc(int tc);
void		ft_left_arrow(int *cursor);
void		ft_right_arrow(int *cursor);
void		ft_backspace(int *cursor, int *len);
void		ft_add_history(void);
void		ft_up_arrow(int *cursor, int *len);
void		ft_down_arrow(int *cursor, int *len);
void		ft_init_term(void);
void		ft_reset_term(void);

#endif