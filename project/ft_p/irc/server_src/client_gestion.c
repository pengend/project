/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:30:07 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 18:49:36 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <irc.h>
#include <func.h>

int message_exception_gestion(char *request, t_client *client, int cli, int *number)
{
	int i;
	char **args;

	i = 0;
	args = ft_strsplit(request, ' ', '\t');
	while (g_func[i].name != NULL)
	{
		if (!ft_strcmp(g_func[i].name, args[0] + 1))
		{
			g_func[i].func(client, cli, args + 1, number);
			ft_freetab(args);
			return (1);
		}
		i++;
	}
	ft_send_msg(cli, ERRORS, "Unknown command");
	ft_freetab(args);
	return (1);
}

int recv_gestion(char *request, t_client *client, int cli, int *number)
{
	char *non_ws;
	char **args;

	non_ws = ft_whitespace(request);
	if (client[cli].fd_stat == I_UNKNOWN)
	{
		args = ft_strsplit(request, ' ', '\t');
		if (ft_nick(client, cli, args, number))
			client[cli].fd_stat = I_CLIENT | WAIT;
		ft_freetab(args);
		free(non_ws);
		return (1);
	}
	if (non_ws[0] == '/')
	{
		message_exception_gestion(non_ws, client, cli, number);
		free(non_ws);
		return (1);
	}
	if (non_ws)
		free(non_ws);
	return (0);
}
