/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_num_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 19:08:54 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 21:16:02 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calq_m_left(t_pile *pile, int s)
{
	t_pile *tmp;
	int i;

	tmp = pile;
	i = 0;
	while (tmp->num != s)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int calq_m_right(t_pile *pile, int s)
{
	t_pile *tmp;
	int i;

	tmp = pile;
	i = 0;
	while (tmp->num != s)
	{
		tmp = tmp->prec;
		i++;
	}
	return (i);
}

t_pile *search_smallest(t_pile *pile, int s)
{
	t_pile *tmp;

	tmp = pile;
	while (tmp->num != s)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void num_select(t_list *pw, int *tab)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (pw->pile1 != NULL)
	{
		if (calq_m_left(pw->pile1, tab[i]) < calq_m_right(pw->pile1, tab[i]))
			while (pw->pile1->num != tab[i])
				rrotate_pile(pw->pile1, pw->p1_len, "ra ", &(pw->opr));
		else
			while (pw->pile1->num != tab[i])
				rotate_pile(pw->pile1, pw->p1_len, "rra ", &(pw->opr));
		push_to_b(pw);
		i++;
		a++;
	}
	pw->opr += a;
	while (a > 0)
	{
		ft_putstr("pa ");
		a--;
	}
}
