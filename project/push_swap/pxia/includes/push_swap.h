/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:37:39 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 21:15:30 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_pile
{
	int num;
	struct s_pile *next;
	struct s_pile *prec;
}				t_pile;

typedef struct s_list
{
	t_pile *pile1;
	t_pile *pile2;
	int opr;
	int len;
	int p1_len;
	int p2_len;
}				t_list;

void quick_sort(int tab[], int start, int end);
void add_end(t_pile **list, t_pile *ele);
t_list get_list(int argc, char **argv);
void swap_all(t_list *pw);
void swap_a(t_list *pw);
void swap_b(t_list *pw);
void push_to_a(t_list *pw);
void push_to_b(t_list *pw);
void rotate_all(t_list *pw);
void rrotate_all(t_list *pw);
void print_num(t_pile *pile, int pile_len);
void rotate_pile(t_pile *pile, int pile_len, char *s, int *opr);
void rrotate_pile(t_pile *pile, int pile_len, char *s, int *opr);
int check_order(t_list pw, int *tab);
void num_select(t_list *pw, int *tab);

#endif
