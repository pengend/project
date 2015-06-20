/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:46:06 by pxia              #+#    #+#             */
/*   Updated: 2015/06/12 19:51:33 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int main(int ac, char **av)
{
	int fd;
	void *data;
	struct stat buff;

	file = "a.out"
	if (ac > 1)
		file = argv[1];
	ft_sys("File test", 0, -10, fd);
	ft_sys("File info", 0, 0, fstat(fd, &buff));
	if ((data = mmap(9, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0) == MAP_FAILED))
	{
		close(fd);
		return (0);
	}
}
