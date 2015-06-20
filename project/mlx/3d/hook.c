/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 22:06:19 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 17:59:37 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

int key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	view_control(keycode, e);
	if (keycode == 65362)
	{
		e->cam.position.z += 10;
		e->cam.target.z += 10;
	}
	if (keycode == 65364)
	{
		e->cam.position.z -= 10;
		e->cam.target.z -= 10;
	}
	fresh_img(&(e->cam));
	wolf_image_to_window(e);
	return (0);
}

int expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
	return (0);
}
