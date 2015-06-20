/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 18:03:20 by pxia              #+#    #+#             */
/*   Updated: 2015/02/02 22:09:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void		ft_trace_d(t_point c1, t_point c2, t_env *e, int c)
{
	int		i;

	i = 0;
	if (c == 1)
		while (i <= ABS(c2.y - c1.y))
		{
			(c2.y > c1.y) ? ppixel1(c1, 0, i, e) : ppixel2(c1, 0, i, e);
			i++;
		}
	else
	{
		while (i <= ABS(c2.x - c1.x))
		{
			(c2.x > c1.x) ? ppixel1(c1, i, 0, e) : ppixel2(c1, i, 0, e);
			i++;
		}
	}
}

void		ft_trace1(double a, t_point c1, t_point c2, t_env *e)
{
	double	tmp;
	double	b;
	int		ent;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tmp = 0;
	while (i <= ABS(c2.x - c1.x))
	{
		b = i * ABS(a) - tmp;
		ent = (b - floor(b) >= floor(b) + 1 - b) ?
			floor(b) + 1 : floor(b);
		tmp += ent;
		while (ent--)
		{
			(c2.x > c1.x) ? ppixel1(c1, i, j, e) : ppixel2(c1, i, j, e);
			j += (a < 0) ? -1 : 1;
		}
		i++;
	}
}

void		ft_trace0(double a, t_point c1, t_point c2, t_env *e)
{
	int		i;
	int		j;
	int		max;
	double	tmp;

	i = 1;
	j = 0;
	max = ABS(c1.x - c2.x);
	tmp = 0;
	while (i <= max)
	{
		while (i * ABS(a) - tmp < 1 && i <= max)
		{
			(c2.x > c1.x) ? ppixel1(c1, i, j, e) : ppixel2(c1, i, j, e);
			i++;
		}
		tmp = floor(i * ABS(a));
		j += (a < 0) ? -1 : 1;
	}
}

void				ft_trace_line(t_point c1, t_point c2, t_env *e)
{
	double			a;

	a = (c2.y - c1.y) / 1.0 / (c2.x - c1.x);
	if (ABS(c2.x - c1.x) == 0)
	{
		ft_trace_d(c1, c2, e, 1);
	}
	else if (ABS(c2.y - c1.y) == 0)
	{
		ft_trace_d(c1, c2, e, 0);
	}
	else
	{
		if (ABS(a) > 1)
			ft_trace1(a, c1, c2, e);
		else
			ft_trace0(a, c1, c2, e);
	}
}
