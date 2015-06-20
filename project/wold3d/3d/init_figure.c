/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 22:06:31 by pxia              #+#    #+#             */
/*   Updated: 2015/01/24 22:41:55 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

t_list *init_figure_list(int const fd)
{
	t_list *mod;
	char **tab;

	
}

t_list *init_figure_check(int const fd, char *figure_name)
{
	char *line;
	int i;

	i =	get_next_line(fd, &line);
	if (ft_strcmp(line, ".peng"))
		return (NULL);
	while (ft_strcmp(line, figure_name))
	{
		i = get_next_line(fd, &line);
		if (i == 0)
			return (NULL);
	}
	return (get_figure_list(fd));
}

int main()
{
	int fd;

	fd = open("doc.txt", O_RDONLY);
	init_figure_check(fd, "square:");
}
