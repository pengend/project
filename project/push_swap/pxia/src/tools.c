/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:33:59 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 21:07:43 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_end(t_pile **list, t_pile *ele)
{
	t_pile *tmp;

	if (*list == NULL)
	{
		*list = ele;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	ele->prec = tmp;
	tmp->next = ele;
}

int check_order(t_list pw, int *tab)
{
	int i;
	t_pile *tmp;

	if (pw.pile2 != NULL)
		return (0);
	tmp = pw.pile1;
	i = 0;
	while (i < pw.p1_len)
	{
		if (tab[i] != tmp->num)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void print_num(t_pile *pile, int pile_len)
{
	t_pile *tmp;
	int i;

	tmp = pile;
	i = 0;
	while (i < pile_len)
	{
		ft_putnbr(tmp->prec->num);
		ft_putchar(' ');
		tmp = tmp->prec;
		i++;
	}
	ft_putchar('\n');
}

