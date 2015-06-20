/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:51:48 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 17:35:52 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void init_img(t_env *e)
{
	e->i->mlx = e->mlx;
	e->i->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->i->data = mlx_get_data_addr(
		e->i->img, &(e->i->bpp), &(e->i->size_line), &(e->i->endian));
}

int main()
{
	t_env e;

	if ((e.mlx = mlx_init()) == NULL)
		return (0);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "ras");
	e.i = (t_img*)malloc(sizeof(t_img));
	init_img(&e);
	init_cam(&(e.cam));
	fresh_img(&(e.cam));
	trace_cubes(&e);
	mlx_put_image_to_window(e.mlx, e.win, (e.i)->img, 0, 0);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
