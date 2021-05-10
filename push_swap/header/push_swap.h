/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:19 by suhong            #+#    #+#             */
/*   Updated: 2021/05/10 15:27:02 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

#if 0
int	get_pivot(t_deck *start, size_t size, int *pivot);
#else
int	get_pivot(t_stack *start, size_t size);
#endif
int	quick_a_2_b(t_stack *a, t_stack *b, size_t size);
int	quick_b_2_a(t_stack *a, t_stack *b, size_t size);

#endif
