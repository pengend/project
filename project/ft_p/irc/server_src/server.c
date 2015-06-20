/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:35:31 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 17:47:30 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void	init_server(t_socket *serv, char *portnum)
{
	struct protoent *proto;

	proto = getprotobyname("tcp");
	if (proto == 0)
		ft_sys("Wrong protocol", 2, 2, 3);
	serv->sockfd = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	ft_sys("Openning socket", -1, -10, serv->sockfd);
	ft_bzero((char*)(&serv->addr), sizeof(serv->addr));
	serv->port = ft_atoi(portnum);
	serv->addr.sin_family = AF_INET;
	serv->addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv->addr.sin_port = htons(ft_atoi(portnum));
}

int		main(int argc, char **argv)
{
	t_socket serv;

	ft_sys("Number of argument", 2, 2, argc);
	init_server(&serv, argv[1]);
	ft_sys("Binding", 0, 0, bind(serv.sockfd, (struct sockaddr *)&serv.addr, sizeof(serv.addr)) < 0);
	ft_sys("Listenning", 0, 0, listen(serv.sockfd, 5));
	chat_system(serv);
	close(serv.sockfd);
	return (0);
}
