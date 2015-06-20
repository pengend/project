/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 20:14:51 by pxia              #+#    #+#             */
/*   Updated: 2015/05/22 16:40:56 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

int ft_quit(t_client *client, int cli, char **args, int *number)
{
	(void)args;
	(void)client;
	remove_client(cli, number);
	return (1);
}
