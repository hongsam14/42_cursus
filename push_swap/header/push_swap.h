/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:19 by suhong            #+#    #+#             */
/*   Updated: 2021/05/13 11:44:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef struct s_chunk
{
	size_t	push_log;
	size_t	ra_log;
	size_t	rb_log;
	int	pivot_l;
	int	pivot_h;
}	t_chunk;

int	get_pivot(t_stack *start, size_t *size, int *p_l, int *p_h);
void	init_chunk(t_chunk *chunk);
int	chunk_sort_check(t_stack *stack, size_t size, int flag);
int	work_log(t_stack *a, t_stack *b, char *str, size_t *log);
void	rotate_stack(t_stack *a, t_stack *b, size_t ra, size_t rb);
int		a_2_b(t_stack *a, t_stack *b, size_t size);
int		b_2_a(t_stack *a, t_stack *b, size_t size);

#endif
