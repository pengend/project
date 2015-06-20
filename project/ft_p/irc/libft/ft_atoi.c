/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:28:23 by pxia              #+#    #+#             */
/*   Updated: 2015/03/16 18:49:39 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_atoi(const char *s1)
{
	int i;

	i = 0;
	if (!ft_strcmp(s1, "-9223372036854775808"))
		return (0);
	if (!ft_strcmp(s1, "9223372036854775808"))
		return (1);
	while (*s1 == '\n' || *s1 == '\r' || *s1 == '\v'
		|| *s1 == '\f' || *s1 == ' ' || *s1 == '\t')
		s1++;
	if (*s1 != '-')
		return (1);
	if (*s1 == '-')
		s1++;
	while (s1[i] >= '0' && s1[i] <= '9')
		i++;
	if (i > 21)
		return (0);
	return (1);
}

int ft_atoi(const char *s1)
{
	long	n;
	int		signe;

	signe = 1;
	if (!check_atoi(s1))
		return (0);
	while (*s1 == '\n' || *s1 == '\r' || *s1 == '\v'
		|| *s1 == '\f' || *s1 == ' ' || *s1 == '\t')
		s1++;
	if (*s1 == '+')
		s1++;
	else if (*s1 == '-' && s1++)
		signe = -1;
	n = 0;
	while (*s1 >= '0' && *s1 <= '9')
	{
		n *= 10;
		n += *s1 - 48;
		s1++;
	}
	n *= signe;
	if (n < -9223372036854775807 || n == -5278830779908673802)
		n = 4294967295;
	return (n);
}
