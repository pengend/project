/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 13:38:42 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 20:58:49 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void delete_maillon(t_pile **pile)
{
	if ((*pile)->next == (*pile))
	{
		*pile = NULL;
		return ;

	}
	(*pile)->prec->next = (*pile)->next;
	(*pile)->next->prec = (*pile)->prec;
	(*pile) = (*pile)->next;
}

void add_maillon(t_pile **dst, t_pile *pile)
{
	if (*dst == NULL)
	{
		pile->next = pile;
		pile->prec = pile;
		*dst = pile;
	}
	else
	{
		pile->next = (*dst);
		pile->prec = (*dst)->prec;
		(*dst)->prec->next = pile;
		(*dst)->prec = pile;
		(*dst) = pile;
	}
}

void push_maillon(t_pile **src, t_pile **dst)
{
	t_pile *tmp;

	tmp = *src;
	delete_maillon(src);
	add_maillon(dst, tmp);
}

void push_to_a(t_list *pw)
{
	if (pw->pile2 == NULL)
		return ;
	push_maillon(&(pw->pile2), &(pw->pile1));
	pw->p2_len--;
	pw->p1_len++;
	pw->opr++;
	ft_putstr("pa ");
}

void push_to_b(t_list *pw)
{
	if (pw->pile1 == NULL)
		return ;
	push_maillon(&(pw->pile1), &(pw->pile2));
	pw->p1_len--;
	pw->p2_len++;
	pw->opr++;
	ft_putstr("pb ");
}
