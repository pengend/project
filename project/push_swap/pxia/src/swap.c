/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:21:43 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 18:24:35 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_pile(t_pile *pile, char *s)
{
	int tmp;

	if (pile != NULL)
	{
		tmp = pile->num;
		pile->num = pile->prec->num;
		pile->prec->num = tmp;
		if (s)
			ft_putstr(s);
	}
}

void swap_all(t_list *pw)
{
	swap_pile(pw->pile1, "ss ");
	swap_pile(pw->pile2, NULL);
	pw->opr++;
}

void swap_a(t_list *pw)
{
	swap_pile(pw->pile1, "sa ");
	pw->opr++;
}

void swap_b(t_list *pw)
{
	swap_pile(pw->pile2, "sb ");
	pw->opr++;
}
