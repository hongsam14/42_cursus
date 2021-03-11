/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:01:08 by suhong            #+#    #+#             */
/*   Updated: 2021/03/11 18:46:55 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLER_H
# define CONTROLER_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

# define KEY_W					13
# define KEY_S					1
# define KEY_A					0
# define KEY_D					2
# define KEY_ARROW_R			124
# define KEY_ARROW_L			123
# define KEY_ESC				53

# define W_FLAG					8
# define S_FLAG					4
# define A_FLAG					2
# define D_FLAG					1
# define L_FLAG					2
# define R_FLAG					1
# define ESC_FLAG				1

typedef struct	s_control
{
	int			movement : 4;
	int			rotation : 2;
	int			exit : 1;
}				t_control;

void			init_control(t_control *control);
int				key_press(int keycode, t_control *control);
int				key_release(int keycode, t_control *control);

#endif
