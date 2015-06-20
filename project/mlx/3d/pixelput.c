/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:40:35 by pxia              #+#    #+#             */
/*   Updated: 2015/02/16 19:59:32 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void put_pixel_to_img(t_img *im, int x, int y, unsigned int cl)
{
	unsigned int color;

	x += WIDTH / 2;
	y *= -1;
	y += HEIGHT / 2;
	if (x >= WIDTH)
		return ;
	else if (x < 0)
		return ;
	if (y >= HEIGHT)
		return ;
	else if (y < 0)
		return ;
	color = mlx_get_color_value(im->mlx, cl);
	im->data[y * im->size_line + im->bpp / 8 * x] = (color & 0xFF);
	im->data[y * im->size_line + im->bpp / 8 * x + 1] = (color & 0xFF00) >> 8;
	im->data[y * im->size_line + im->bpp / 8 * x + 2] =
		(color & 0xFF0000) >> 16;
}

void ppixel1(t_point c1, int i, int j, t_env *e)
{
	put_pixel_to_img(e->i, c1.x + i, c1.y + j, 0xFFFFFF);
}

void ppixel2(t_point c1, int i, int j, t_env *e)
{
	put_pixel_to_img(e->i, c1.x - i, c1.y - j, 0xFFFFFF);
}
