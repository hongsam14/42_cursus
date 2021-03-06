/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:24:25 by suhong            #+#    #+#             */
/*   Updated: 2021/03/06 15:08:08 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controler.h"

void	init_control(t_control *control)
{
	control->movement = 0b0000;
	control->rotation = 0b00;
	control->exit = 0b0;
}

int		key_press(int keycode, t_control *control)
{
	if (keycode == KEY_W)
		control->movement |= W_FLAG;
	if (keycode == KEY_S)
		control->movement |= S_FLAG;
	if (keycode == KEY_A)
		control->movement |= A_FLAG;
	if (keycode == KEY_D)
		control->movement |= D_FLAG;
	if (keycode == KEY_ARROW_L)
		control->rotation |= L_FLAG;
	if (keycode == KEY_ARROW_R)
		control->rotation |= R_FLAG;
	return (0);
}

int		key_release(int keycode, t_control *control)
{
	if (keycode == KEY_W)
		control->movement &= ~W_FLAG;
	if (keycode == KEY_S)
		control->movement &= ~S_FLAG;
	if (keycode == KEY_A)
		control->movement &= ~A_FLAG;
	if (keycode == KEY_D)
		control->movement &= ~D_FLAG;
	if (keycode == KEY_ARROW_L)
		control->rotation &= ~L_FLAG;
	if (keycode == KEY_ARROW_R)
		control->rotation &= ~R_FLAG;
	if (keycode == KEY_ESC)
		control->exit |= 0b1;
	return (0);
}
