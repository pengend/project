/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:03:32 by pxia              #+#    #+#             */
/*   Updated: 2015/01/21 21:14:13 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ras.h"

int main()
{
	int fd;
	char *line;
	char *buff;
	int ret;

	fd = open("doc.txt", O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
	buff = ft_strnew(10);
	ret = read(fd, buff, 10);
	buff[ret] = '\0';
	ft_putstr(buff);
//	get_next_line(fd, &line);
}
