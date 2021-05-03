/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:19 by suhong            #+#    #+#             */
/*   Updated: 2021/05/02 21:33:14 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int	get_middle(t_stack *stack, int *middle, int *m_count);
int	push_little(t_stack *a, t_stack *b, int mid, int count);
int	push_big(t_stack *a, t_stack *b, int mid, int count);
int	push_a_2_b(t_stack *a, t_stack *b);
int	push_b_2_a(t_stack *a, t_stack *b);
int	push_b_all(t_stack *a, t_stack *b);

#endif
