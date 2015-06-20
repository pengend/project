/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:26:02 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 19:29:44 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile *get_pile(char **argv)
{
	t_pile *pile;
	t_pile *tmp;

	pile = NULL;
	while (*argv)
	{
		tmp = (t_pile*)malloc(sizeof(t_pile));
		tmp->num = ft_atoi(*argv);
		argv++;
		if (!*argv)
		{
			tmp->next = pile;
			pile->prec = tmp;
			pile = tmp;
		}
		else
			tmp->next = NULL;
		add_end(&pile, tmp);			
	}
	if (pile)
		pile = pile->next;
	return (pile);
}

t_list get_list(int argc, char **argv)
{
	t_list pw;
 
	pw.pile1 = get_pile(argv);
	pw.pile2 = NULL;
	pw.opr = 0;
	pw.p1_len = argc;
	pw.len = argc;
	pw.p2_len = 0;
	return (pw);
}
