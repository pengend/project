/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 18:05:32 by pxia              #+#    #+#             */
/*   Updated: 2015/05/27 18:34:40 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACK_H

#define PACK_H

#include "irc.h"

typedef struct	s_pfunc
{
	char		req;
	void		(*func)(int cli, int sockfd);
}				t_pfunc;

t_pfunc g_pfunc[] = 
{
	{RS, prepare_dl_mission},
	{ACK, recv_ack},
	{NAK, recv_nack},
	{ACP, recv_acp},
	{RFD, recv_rfd},
	{0, NULL}
};

#endif

