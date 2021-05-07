/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:31 by suhong            #+#    #+#             */
/*   Updated: 2021/05/07 15:22:54 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "my_stack.h"
# include "../libft/libft.h"

int		put_int_2_stack(t_stack *stack, int argc, char *argv[]);
int		order(char *str, t_stack *a, t_stack *b);
void	print_a_b_stack(t_stack *a, t_stack *b);
int		print_order(char *str, t_stack *a, t_stack *b);

#endif
