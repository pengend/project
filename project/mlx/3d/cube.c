/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:13:16 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 18:29:44 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void trace_cube(t_cb cube_projection, t_env *e)
{
	ft_trace_line(cube_projection.p1, cube_projection.p2, e);
	ft_trace_line(cube_projection.p2, cube_projection.p3, e);
	ft_trace_line(cube_projection.p3, cube_projection.p4, e);
	ft_trace_line(cube_projection.p4, cube_projection.p1, e);
	ft_trace_line(cube_projection.p5, cube_projection.p6, e);
	ft_trace_line(cube_projection.p6, cube_projection.p7, e);
	ft_trace_line(cube_projection.p7, cube_projection.p8, e);
	ft_trace_line(cube_projection.p8, cube_projection.p5, e);
	ft_trace_line(cube_projection.p1, cube_projection.p5, e);
	ft_trace_line(cube_projection.p2, cube_projection.p6, e);
	ft_trace_line(cube_projection.p3, cube_projection.p7, e);
	ft_trace_line(cube_projection.p4, cube_projection.p8, e);	
}

t_cb init_cube(int x, int y, int z)
{
	t_cb cube;

	cube.p1 = init_coor(x, y, z);
	cube.p2 = init_coor(x, y + 20, z);
	cube.p3 = init_coor(x + 20, y + 20, z);
	cube.p4 = init_coor(x + 20, y, z);
	cube.p5 = init_coor(x, y, z + 20);
	cube.p6 = init_coor(x, y + 20, z + 20);
	cube.p7 = init_coor(x + 20, y + 20, z + 20);
	cube.p8 = init_coor(x + 20, y, z + 20);
	return (cube);
}

t_cb init_projection(t_cb cube, t_env *e)
{
	t_cb projection;

	projection.p1 = build_mat(matrix_multiply(matrix_multiply(cube.p1, e->cam.tra), e->cam.rot));
	projection.p2 = build_mat(matrix_multiply(matrix_multiply(cube.p2, e->cam.tra), e->cam.rot));
	projection.p3 = build_mat(matrix_multiply(matrix_multiply(cube.p3, e->cam.tra), e->cam.rot));
	projection.p4 = build_mat(matrix_multiply(matrix_multiply(cube.p4, e->cam.tra), e->cam.rot));
	projection.p5 = build_mat(matrix_multiply(matrix_multiply(cube.p5, e->cam.tra), e->cam.rot));
	projection.p6 = build_mat(matrix_multiply(matrix_multiply(cube.p6, e->cam.tra), e->cam.rot));
	projection.p7 = build_mat(matrix_multiply(matrix_multiply(cube.p7, e->cam.tra), e->cam.rot));
	projection.p8 = build_mat(matrix_multiply(matrix_multiply(cube.p8, e->cam.tra), e->cam.rot));
/*	projection.p1 = matrix_multiply(cube.p1, e->cam.rot);
	projection.p2 = matrix_multiply(cube.p2, e->cam.rot);
	projection.p3 = matrix_multiply(cube.p3, e->cam.rot);
	projection.p4 = matrix_multiply(cube.p4, e->cam.rot);
	projection.p5 = matrix_multiply(cube.p5, e->cam.rot);
	projection.p6 = matrix_multiply(cube.p6, e->cam.rot);
	projection.p7 = matrix_multiply(cube.p7, e->cam.rot);
	projection.p8 = matrix_multiply(cube.p8, e->cam.rot);
	printf("\n");
	printf("%.3f %.3f %.5f\n", projection.p1.x, projection.p1.y, projection.p1.w);
	printf("%.3f %.3f %.5f\n", projection.p2.x, projection.p2.y, projection.p2.w);
	printf("%.3f %.3f %.5f\n", projection.p3.x, projection.p3.y, projection.p3.w);
	printf("%.3f %.3f %.5f\n", projection.p4.x, projection.p4.y, projection.p4.w);
	printf("%.3f %.3f %.5f\n", projection.p5.x, projection.p5.y, projection.p5.w);
	printf("%.3f %.3f %.5f\n", projection.p6.x, projection.p6.y, projection.p6.w);
	printf("%.3f %.3f %.5f\n", projection.p7.x, projection.p7.y, projection.p7.w);
	printf("%.3f %.3f %.5f\n", projection.p8.x, projection.p8.y, projection.p8.w);
*/	printf("\n");
	return (projection);
}

void trace_cubes(t_env *e)
{
	int x;
	int y;
	int z;

	x = -100;
	while (x < 400)
	{
		y = 0;
		while (y < 20)
		{
			z = 11;
			while (z < 31)
			{ 
				trace_cube(init_projection(init_cube(x, y, z), e), e);
				z += 20;
			}
			y += 20;
		}
		x += 20;
	}
}
