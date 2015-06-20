/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 12:07:43 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 21:01:34 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrotate_pile(t_pile *pile, int pile_len, char *s, int *opr)
{
	int i;
	t_pile *ptmp;
	int tmp;

	i = 0;
	if (pile_len == 0 || pile == NULL)
		return ;
	ptmp = pile;
	tmp = ptmp->num;
	while (i < pile_len - 1)
	{
		ptmp->num = ptmp->prec->num;
		ptmp = ptmp->prec;
		i++;
	}
	ptmp->num = tmp;
	if (s)
		ft_putstr(s);
	(*opr)++;
}

void rotate_pile(t_pile *pile, int pile_len, char *s, int *opr)
{
	int i;
	t_pile *ptmp;
	int tmp;

	i = 0;
	if (pile_len == 0 || pile == NULL)
		return ;
	ptmp = pile;
	tmp = ptmp->num;
	while (i < pile_len - 1)
	{
		ptmp->num = ptmp->next->num;
		ptmp = ptmp->next;
		i++;
	}
	ptmp->num = tmp;
	if (s)
		ft_putstr(s);
	(*opr)++;
}

void rotate_all(t_list *pw)
{
	rotate_pile(pw->pile1, pw->p1_len, NULL, &(pw->opr));
	rotate_pile(pw->pile2, pw->p2_len, NULL, &(pw->opr));
	ft_putstr("rr ");
	pw->opr++;
}

void rrotate_all(t_list *pw)
{
	rrotate_pile(pw->pile1, pw->p1_len, NULL, &(pw->opr));
	rrotate_pile(pw->pile2, pw->p2_len, NULL, &(pw->opr));
	ft_putstr("rrr ");
	pw->opr++;
}
