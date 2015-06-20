/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:27:05 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 18:11:14 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void confirm_send_file(t_client *client, int cli, t_confirm *conf)
{
	
}

int ft_sfile(t_client *client, int cli, char **args, int *number);
{
	int to_send_id;
	t_download *tmp;
	char *name;
	char *msg;

	if ((to_send_id = check_args_name(client, cli, args, number)) == -1)
		return (0);
	tmp = (t_download*)malloc(sizeof(t_download));
	tmp->id = ft_strlen(g_base->count_dl);
	g_base->count_dl[tmp->id] = '1';
	tmp->stat = (WAIT | CONFIRM);
	tmp->sd = &(client[cli]);
	tmp->rv = &(client[to_send_id]);
	tmp->name = ft_strdup(args[1]);
	tmp->next = NULL;
	add_end(&(g_base.dl), tmp);
	ft_send_msg(cli, INFO, "Waiting for answer");
	msg = ft_join_all(, "Do you want to receive the file ", tmp->name, " from ", client[cli].name);
	ft_send_msg(to_send_id, INFO, msg);
	free(msg);
	return (1);
}
