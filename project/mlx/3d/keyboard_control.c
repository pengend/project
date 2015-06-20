/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:47:21 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 18:03:21 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void key_rotate(int command, t_env *e)
{
	double tmp_dx;

	tmp_dx = e->cam.target.x;
	if (command == RIGHT)
	{
		e->cam.target.x = e->cam.target.x * cos(-0.05) - e->cam.target.z * sin(-0.05);
		e->cam.target.z = tmp_dx * sin(-0.05) + e->cam.target.z * cos(-0.05);
	}
	else if (command == LEFT)
	{
		e->cam.target.x = e->cam.target.x * cos(0.05) - e->cam.target.z * sin(0.05);
		e->cam.target.z = tmp_dx * sin(0.05) + e->cam.target.z * cos(0.05);
	}
}

void view_control(int command, t_env *e)
{
	if (command == RIGHT || command == LEFT)
		key_rotate(command, e);
}
