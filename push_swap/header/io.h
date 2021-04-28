/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:30:31 by suhong            #+#    #+#             */
/*   Updated: 2021/04/27 19:57:44 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "my_stack.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

int	put_int_2_stack(t_stack *stack, int argc, char *argv[]);

int	get_input_str(t_stack *a, t_stack *b);

#endif
