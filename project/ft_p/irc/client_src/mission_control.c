/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mission_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:19:37 by pxia              #+#    #+#             */
/*   Updated: 2015/06/05 17:52:37 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

t_sd_mission *search_mission(t_file_info info)
{
	t_sd_mission *tmp;

	tmp = g_sd;
	while (tmp->next && (ft_strcmp(tmp->info.rv, info.rv)
						 || ft_strcmp(tmp->info.name, info.name)))
		tmp = tmp->next;
	if (!tmp->next)
		return (NULL);
	return (tmp->next);
}

void delete_mission(int sockfd)
{
	char c;
	t_sd_mission *tmp;
	t_sd_mission *dl;
	t_file_info info;

	recv(sockfd, &c, 1, 0);
	recv(sockfd, &info, sizeof(info), 0);
	if (g_sd && !ft_strcmp(g_sd->info.rv, info.rv)
		   && !ft_strcmp(g_sd->info.name, info.name))
	{
		tmp = g_sd;
		g_sd = g_sd->next;
		free(tmp);
	}
	else
	{
		if ((dl = search_mission(info)) == NULL)
			return ;
		tmp = dl->next;
		dl->next = tmp->next;
		free(tmp);
	}
	ft_sys_msg(CLIENT, ERRORS, C_RED, "Request refused");
}

void start_mission(int sockfd)
{
	char c;
	t_file_info info;
	t_sd_mission *dl;
	
	recv(sockfd, &c, 1, 0);
	recv(sockfd, &info, sizeof(info), 0);
	if (g_sd && !ft_strcmp(g_sd->info.rv, info.rv)
		   && !ft_strcmp(g_sd->info.name, info.name))
	{
		g_sd->info.id = info.id;
	}
	else
	{
		if ((dl = search_mission(info)) == NULL)
			return ;
		dl->next->info.id = info.id;
	}
	ft_sys_msg(CLIENT, INFO, C_YELLOW, "Start sending (confirmation received)");
}
