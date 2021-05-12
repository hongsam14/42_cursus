/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:19 by suhong            #+#    #+#             */
/*   Updated: 2021/05/12 14:13:21 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int	get_pivot(t_stack *start, size_t *size, int *p_l, int *p_h);
int		a_2_b(t_stack *a, t_stack *b, size_t size);
int		b_2_a(t_stack *a, t_stack *b, size_t size);

#endif
