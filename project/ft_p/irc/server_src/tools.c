/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:05:44 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 16:53:15 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int ft_send_msg(int cli, char *type, char *to_send)
{
	char *msg;
	char *msg_type;

	if (!ft_strcmp(type, ERRORS))
		msg_type = ft_join_all(6, C_RED, type, C_RESET, C_BOLD, to_send, C_RESET);
	else
		msg_type = ft_join_all(6, C_YELLOW, type, C_RESET, C_BOLD, to_send, C_RESET);
	msg = ft_join_all(4, C_GREEN, "[FROM SERVER]", C_RESET, msg_type);
	ft_strcat(g_base->client[cli].write_buf, msg);
	free(msg);
	free(msg_type);
	return (1);
}

void ft_send_answer(t_client *dest, int type, t_file_info *info)
{
	char *write_buf;

	write_buf = dest->write_buf;
	write_buf[0] = type;
	ft_memcpy(write_buf + 1, info, sizeof(*info));
}

void ft_send_ack(t_client *dest, int type, int *id)
{
	char *write_buf;

	write_buf = dest->write_buf;
	write_buf[0] = type;
	ft_memcpy(write_buf + 1, id, sizeof(*id));	
}

t_download *search_dl_mission(int id)
{
	t_download *tmp;

	tmp = g_base->dl;
	while (tmp != NULL)
	{
		if (tmp->id == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void add_end(t_download **liste, t_download *new)
{
	t_download *tmp;

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

void delete_dl(t_download *dl)
{
	t_download *tmp;

	tmp = g_base->dl;
	if (tmp == dl)
	{
		g_base->dl = g_base->dl->next;
		free(tmp);
	}
	else
	{
		while (tmp && tmp->next != dl)
			tmp = tmp->next;
		if (!tmp)
			return ;
		tmp->next = dl->next;
		free(dl);
	}
	g_base->count_id[dl->id] = '\0';
}
