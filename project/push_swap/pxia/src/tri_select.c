/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:28:24 by pxia              #+#    #+#             */
/*   Updated: 2015/03/18 16:34:17 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int compare_pile(int sort_tab, t_pile *pile, int len)
{
	int i;
	t_pile *tmp;

	i = 0;
	tmp = pile;
	while (i < len)
	{
		if (sort_tab[i] != tmp->num)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void tri_select(int sort_tab[], t_list *pw)
{
	if (pw->pile2 == NULL)
		compare_pile(sort_tab, pw->pile1, pw->len);
	
}
