/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:01:08 by suhong            #+#    #+#             */
/*   Updated: 2021/02/18 06:23:56 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLER_H
# define CONTROLER_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT		17

# define KEY_W			13
# define KEY_S			1
# define KEY_A			0
# define KEY_D			2
# define KEY_ARROW_R		124
# define KEY_ARROW_L		123
# define KEY_ESC		53

# define W_FLAG			0b1000
# define S_FLAG			0b0100
# define A_FLAG			0b0010
# define D_FLAG			0b0001
# define L_FLAG			0b10
# define R_FLAG			0b01
# define ESC_FLAG		0b1

typedef struct	s_control
{
	int	movement : 4;
	int	rotation : 2;
	int	exit : 1;
}		t_control;

void	init_control(t_control *control);
int		key_press(int keycode, t_control *control);
int		key_release(int keycode, t_control *control);

#endif
