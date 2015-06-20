/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 17:22:00 by pxia              #+#    #+#             */
/*   Updated: 2015/05/27 18:52:14 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void add_end(t_sd_mission **liste, t_sd_mission *new)
{
	t_sd_mission *tmp;

	if (*liste == NULL)
	{
		*liste = new;
		return ;
	}
	tmp = *liste;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void add_sd(int fd, t_file_info info)
{
	t_sd_mission *new;

	new = (t_sd_mission*)malloc(sizeof(t_sd_mission));
	new->fd = fd;
	new->info = info;
	new->stat = WAIT;
	new->max_size = info.size;
	new->size = 0;
	new->next = NULL;
	add_end(&g_sd, new);
}

int ft_send_file(char **args)
{
	int fd;
	struct stat buff;
	t_file_info info;

	if (ft_tablen(args) != 2)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "Invalid argument"));
	if ((fd = open(args[1], O_RDONLY)) == -1)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "On openning file"));
	if (ft_strlen(args[0]) > 9)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "too long name"));
	fstat(fd, &buff);
	ft_strncpy(info.rv, args[0], 9);
	ft_bzero(info.name, MSG_SIZE);
	ft_strcpy(info.name, args[1]);
	info.size = buff.st_size;
	info.id = -1;
	g_write_buf[0] = RS;
	ft_memcpy(g_write_buf + 1, &info, sizeof(info));
	add_sd(fd, info);
	return (1);
}
