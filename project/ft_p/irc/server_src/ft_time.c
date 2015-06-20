/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:06:40 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 16:19:43 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int ft_time(t_client *client, int cli, char **args, int *number)
{
	time_t t;

	(void)args;
	(void)number;
	(void)client;
	t = time(&t);
	ft_send_msg(cli, INFO, ctime(&t));
	return (1);
}
