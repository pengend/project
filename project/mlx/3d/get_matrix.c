/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:15:05 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 17:12:20 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void get_rot(t_cam *cam)
{
	cam->rot[0] = cam->ufr.right.x;
	cam->rot[1] = cam->ufr.right.y;
	cam->rot[2] = cam->ufr.right.z;
	cam->rot[3] = 0;
	cam->rot[4] = cam->ufr.up.x;
	cam->rot[5] = cam->ufr.up.y;
	cam->rot[6] = cam->ufr.up.z;
	cam->rot[7] = 0;
	cam->rot[8] = cam->ufr.forward.x;
	cam->rot[9] = cam->ufr.forward.y;
	cam->rot[10] = cam->ufr.forward.z;
	cam->rot[11] = 0;
	cam->rot[12] = 0;
	cam->rot[13] = 0;
	cam->rot[14] = 0;
	cam->rot[15] = 1;
	printf("rot\n");
	int i = 0;
	while (i < 15)
	{
		printf("%.f %.f %.f %.f\n", cam->rot[i], cam->rot[i + 1], cam->rot[i + 2], cam->rot[i + 3]);
		i += 4;
	}
}

void get_tra(t_cam *cam)
{
	cam->tra[0] = 1;
	cam->tra[1] = 0;
	cam->tra[2] = 0;
	cam->tra[3] = -cam->position.x;
	cam->tra[4] = 0;
	cam->tra[5] = 1;
	cam->tra[6] = 0;
	cam->tra[7] = -cam->position.y;
	cam->tra[8] = 0;
	cam->tra[9] = 0;
	cam->tra[10] = 1;
	cam->tra[11] = -cam->position.z;
	cam->tra[12] = 0;
	cam->tra[13] = 0;
	cam->tra[14] = 0;
	cam->tra[15] = 1;
	printf("tra\n");
	int i = 0;
	while (i < 15)
	{
		printf("%.f %.f %.f %.f\n", cam->tra[i], cam->tra[i + 1], cam->tra[i + 2], cam->tra[i + 3]);
		i += 4;
	}
}

t_point build_mat(t_point point)
{
	t_point new;
	double fov;
	double aspect;
	double zn;
	double zf;

	fov = M_PI / 3;
	aspect = 1.5;
	zn = 1.0;
	zf = 1000.0;
	new.x = point.x * (tan(fov / 2) / aspect);
	new.y = point.y * (tan(fov / 2));
	new.w = point.z;
	new.z = point.z * (zf + zn) / (zf - zn) + (2 * zf * zn) / (zn - zf) * new.w;
	if (new.w < 1)
	{
		new.x = en(point.x / 1.0 / (1.0 / WIDTH * 10));
		new.y = en(point.y / 1.0 / (1.0 / HEIGHT * 10));
	}
	else
	{
		new.x = en(point.x / 1.0 / (new.w / WIDTH * 10));
		new.y = en(point.y / 1.0 / (new.w / HEIGHT * 10));
	}
	return (new);
}

void init_matrix(t_cam *cam)
{
	get_rot(cam);
	get_tra(cam);
}
