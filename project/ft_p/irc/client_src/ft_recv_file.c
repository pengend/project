/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 20:07:59 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 18:00:12 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int check_rv_dl(int id)
{
	t_sd_mission *tmp;

	tmp = g_rv;
	while (tmp != NULL)
	{
		if (tmp->info.id == id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_sd_mission *search_id(int id, t_sd_mission *start)
{
	t_sd_mission *tmp;

	tmp = start;
	while (tmp && tmp->info.id != id)
		tmp = tmp->next;
	return (tmp);
}

static int confirm_error(char **args, int *id)
{
	if (ft_tablen(args) != 2)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "Invalid argument"));
	if (!ft_isnum(args[0]))
		return (ft_sys_msg(CLIENT, ERRORS,
						   C_RED, "First argument must be number"));
	*id = ft_atoi(args[0]);
	if (!check_rv_dl(*id))
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "No such id mission"));
	return (1);
}

int ft_recv_file(int sockfd)
{
	char c;
	t_sd_mission *new;
	t_file_info info;
	int id;

	recv(sockfd, &c, 1, 0);
	recv(sockfd, &info, sizeof(info), 0);
	recv(sockfd, &id, sizeof(id), 0);
	if (test_create(info.name))
	{
		client_answer(NAK, &(info));
		return (0);
	}
	new = (t_sd_mission*)malloc(sizeof(t_sd_mission));
	info.id = id;
	new->next = NULL;
	new->fd = -1;
	new->info = info;
	new->stat = WAIT;
	new->max_size = info.size;
	new->size = 0;
	add_end(&g_rv, new);
	ft_sys_msg(CLIENT, INFO, C_YELLOW, "New file received. Type /ms for details");
	return (1);
}

int ft_confirm(char **args)
{
	int ans;
	int id;
	t_sd_mission *tmp;

	if (!confirm_error(args, &id))
		return (0);
	ans = -1;
	tmp = search_id(id, g_rv);
	if (!ft_strcmp(args[1], "yes"))
	{
		ans = ACK;
		create_fd(tmp);
	}
	else if (!ft_strcmp(args[1], "no"))
	{
		ans = NAK;
		delete_rv(id);
	}
	if (ans == -1)
		return (ft_sys_msg(CLIENT, ERRORS, C_RED, "Answer by yes or no"));
	client_answer(ans, &(tmp->info));
	return (1);
}
