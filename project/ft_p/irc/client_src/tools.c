/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 20:53:58 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 17:10:57 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void client_answer(char c, t_file_info *info)
{
	g_write_buf[0] = c;
	ft_memcpy(g_write_buf + 1, info, sizeof(*info));
}

int test_create(char *name)
{
	char *tmp;
	int fd;

	tmp = ft_strjoin("P_Download/", name);
	if ((fd = open(tmp, O_CREAT | O_EXCL | O_TRUNC | O_RDWR)) == -1)
		return (0);
	close(fd);
	free(tmp);
	return (1);
}

void create_fd(t_sd_mission *dl)
{
	char *s;

	s = ft_strjoin("P_Download/", dl->info.name);
	if ((dl->fd = open(s,  O_CREAT | O_EXCL | O_TRUNC | O_RDWR)) == -1)
	{
		client_answer(NAK, &(dl->info));
		ft_sys_msg(CLIENT, ERRORS, C_RED,
					   "File already created in the repository");
		return ;
	}
	dl->stat = CONFIRMED;
	free(s);
}

void delete_rv(int id)
{
	t_sd_mission *tmp;
	t_sd_mission *dl;

	tmp = g_rv;
	if (tmp->info.id == id)
	{
		g_rv = g_rv->next;
		free(tmp);
	}
	else
	{
		while (tmp && tmp->next != NULL)
			tmp = tmp->next;
		if (!tmp)
			return ;
		dl = tmp->next;
		tmp->next = dl->next;
		free(dl);
	}
}
