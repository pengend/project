/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:09:31 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 17:30:24 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_getchar_number(char **split)
{
	int i;
	int lengh;

	i = 0;
	lengh = 0;
	while (split[i])
	{
		lengh += ft_strlen(split[i]);
		i++;
	}
	return (lengh);
}

char *ft_whitespace(char *str)
{
	char **split;
	char *ret;
	int i;
	int lengh;

	split = ft_strsplit(str, ' ', '\t');
	lengh = ft_tablen(split) + ft_getchar_number(split);
	ret = ft_strnew(lengh);
	i = 0;
	while (split[i])
	{
		ft_strcat(ret, split[i]);
		if (split[i + 1] != NULL)
			ft_strcat(ret, " ");
		i++;
	}
	ft_freetab(split);
	return (ret);
}
