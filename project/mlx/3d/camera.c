/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:15:58 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 18:13:19 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

t_point cross_product(t_point u, t_point v)
{
	t_point w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

t_point normalize(t_point u)
{
	double len;
	t_point new;

	len = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
	new.x = u.x / len;
	new.y = u.y / len;
	new.z = u.z / len;
	return (new);
}

void init_cam(t_cam *cam)
{
	cam->position.x = 0;
	cam->position.y = 10;
	cam->position.z = 0;
	cam->target.x = 0;
	cam->target.y = 10;
	cam->target.z = 1;
	cam->roll = 0;
	cam->ufr.up.x = sin(cam->roll);
	cam->ufr.up.y = -cos(cam->roll);
	cam->ufr.up.z = 0;
	cam->ufr.up = normalize(cam->ufr.up);
}

void fresh_img(t_cam *cam)
{
	cam->ufr.forward.x = cam->target.x - cam->position.x;
	cam->ufr.forward.y = cam->target.y - cam->position.y;
	cam->ufr.forward.z = cam->target.z - cam->position.z;
	cam->ufr.forward = normalize(cam->ufr.forward);
	cam->ufr.right = cross_product(cam->ufr.forward, cam->ufr.up);
//	cam->ufr.up = cross_product(cam->ufr.forward, cam->ufr.right);
//	cam->ufr.up = cross_product(cam->ufr.right, cam->ufr.forward);
//	cam->ufr.forward = cross_product(cam->ufr.right, cam->ufr.up);
	init_matrix(cam);
	printf("up : x %.5f y %.5f z %.5f\n", cam->ufr.up.x, cam->ufr.up.y, cam->ufr.up.z);
	printf("fo : x %.5f y %.5f z %.5f\n", cam->ufr.forward.x, cam->ufr.forward.y, cam->ufr.forward.z);
	printf("ri : x %.5f y %.5f z %.5f\n", cam->ufr.right.x, cam->ufr.right.y, cam->ufr.right.z);
	printf("target x %.3f y %.3f z %.3f norm %.5f\n", cam->target.x, cam->target.y, cam->target.z, sqrt(cam->target.x * cam->target.x + cam->target.z * cam->target.z));
}
