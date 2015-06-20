/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:25:17 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 21:15:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int verif_argv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int *get_sort_tab(t_list pw)
{
	int *tab;
	t_pile *lc;
	int i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * pw.len);
	lc = pw.pile1;
	while (i < pw.len)
	{
		tab[i] = lc->num;
		lc = lc->next;
		i++;
	}
	quick_sort(tab, 0, pw.len - 1);
	return (tab);
}

int main(int argc, char **argv)
{
	t_list pw;
	int *tab;

	ft_sys("Verification 1 --argc", 1, -10, argc);
	ft_sys("Verification 2 --number check", 1, 1, verif_argv(argv + 1));
	ft_sys("Starting program --Push Swap", 0, 0, 0);
	pw = get_list(argc - 1, argv + 1);
	print_num(pw.pile1, pw.p1_len);	
	print_num(pw.pile2, pw.p2_len);	
	tab = get_sort_tab(pw);
	num_select(&pw, tab);
	return (0);
}
