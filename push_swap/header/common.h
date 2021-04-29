/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:31 by suhong            #+#    #+#             */
/*   Updated: 2021/04/29 17:28:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "my_stack.h"
# include "../libft/libft.h"

int	put_int_2_stack(t_stack *stack, int argc, char *argv[]);
void	print_stack(t_stack *stack);

#endif
