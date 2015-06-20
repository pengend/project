/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 10:31:59 by pxia              #+#    #+#             */
/*   Updated: 2015/03/18 10:59:43 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void swap(int tab[], int a, int b)
{
  int tmp;

  tmp = tab[a];
  tab[a] = tab[b];
  tab[b] = tmp;
}


void quick_sort(int tab[], int start, int end)
{
  int pivot;
  int left;
  int right;
  
  if (start >= end)
    return ;
  pivot = tab[start];
  left = start;
  right = end;
  while (1)
    {
      if (tab[right] == tab[left])
		  right--;
      while (tab[right] > pivot)
		  right--;
      while (tab[left] < pivot)
		  left++;
      if (left < right)
		  swap(tab, left, right);
      else
		  break ;
    }
  quick_sort(tab, start, right);
  quick_sort(tab, right + 1, end);
}
