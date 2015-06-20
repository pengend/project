/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ras.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:53:32 by pxia              #+#    #+#             */
/*   Updated: 2015/02/17 18:01:54 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAS_H
# define RAS_H

# define ABS(x) ((x) < 0 ? - (x) : (x))
# define WIDTH 1500
# define HEIGHT 1000
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

typedef struct		s_point
{
	double				x;
	double				y;
	double				z;
	double				w;
}					t_point;

typedef struct		s_img
{
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				h;
	int				w;
	unsigned int	color;
}					t_img;

typedef struct		s_cb
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_point			p4;
	t_point			p5;
	t_point			p6;
	t_point			p7;
	t_point			p8;
}					t_cb;

typedef struct		s_ufr
{
	t_point			up;
	t_point			forward;
	t_point			right;
}					t_ufr;

typedef struct		s_cam
{
	t_point			position;
	t_point			target;
	float			roll;
	t_ufr			ufr;
	double			rot[16];
	double			tra[16];
}					t_cam;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*i;
	t_cam			cam;
}					t_env;

void				ft_trace_line(t_point c1, t_point c2, t_env *e);
void				ppixel1(t_point c1, int i, int j, t_env *e);
void				ppixel2(t_point c1, int i, int j, t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				init_matrix(t_cam *cam);
t_point				matrix_multiply(t_point coord, double matrix[16]);
int					en(double n);
t_point				init_coor(int x, int y, int z);
t_point				build_mat(t_point point);
void				trace_cubes(t_env *e);
void				fresh_img(t_cam *cam);
void				wolf_image_to_window(t_env *e);
void				init_cam(t_cam *cam);
void				view_control(int command, t_env *e);

#endif
