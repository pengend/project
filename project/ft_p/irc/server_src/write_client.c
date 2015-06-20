/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:51:19 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:23:34 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void write_client(t_client *client, int cli, char *buff, int *number)
{
	int ret;

	(void)number;
	ret = send(client[cli].cli.sockfd, buff, BLOCK_SIZE, 0);
	if (ret == 0)
		remove_client(cli, number);
}
