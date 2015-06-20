/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:52:33 by pxia              #+#    #+#             */
/*   Updated: 2015/05/27 14:54:55 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <string.h>
typedef struct s_list
{
	int i;
	int a;
	char s[10];
}				t_list;

int main()
{
	printf("%s\n", ft_itoa((int)1121 * 1.0 / 12122 * 100));
}
