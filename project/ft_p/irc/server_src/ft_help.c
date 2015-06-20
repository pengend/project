/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:14:43 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 16:19:27 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"
#include "help.h"

int ft_help(t_client *client, int cli, char **args, int *number)
{
	int i;
	char buff[BLOCK_SIZE];

	(void)args;
	(void)number;
	(void)client;
	ft_bzero(buff, BLOCK_SIZE);
	ft_strcat(buff,
			  "\n--------------------------HELP--------------------------\n");
	i = 0;
	while (g_help[i] != NULL)
	{
		ft_strcat(buff, g_help[i]);
		i++;
	}
	ft_send_msg(cli, INFO, buff);
	return (1);
}
