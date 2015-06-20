/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:21:32 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 17:37:54 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

t_point matrix_multiply(t_point coord, double matrix[16])
{
	t_point new;

	new.x = matrix[0] * coord.x + matrix[1] * coord.y + matrix[2] * coord.z
		+ matrix[3];
	new.y = matrix[4] * coord.x + matrix[5] * coord.y + matrix[6] * coord.z
		+ matrix[7];
	new.z = matrix[8] * coord.x + matrix[9] * coord.y + matrix[10] * coord.z
		+ matrix[11];
	new.w = matrix[12] * coord.w + matrix[13] * coord.w + matrix[14] * coord.w
		+ matrix[15];
	return (new);
}

void wolf_image_to_window(t_env *e)
{
	ft_bzero(e->i->data, HEIGHT * e->i->size_line + e->i->bpp / 8 * WIDTH);
	trace_cubes(e);
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
}

int en(double n)
{
	int ent;

	ent = floor(n);
	ent = n - ent >= ent + 1 - n ? ent + 1 : ent;
	return (ent);
}

t_point init_coor(int x, int y, int z)
{
	t_point coor;

	coor.x = x;
	coor.y = y;
	coor.z = z;
	coor.w = 1;
	return (coor);
}
