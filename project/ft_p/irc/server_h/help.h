/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:21:11 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 19:29:27 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H


char *g_help[] =
{
	"/nick <nickname> : to modify nickname\n",
	"/join <channel_id> : to join channel with id (number)\n",
	"/leave : leave current channel and join default channel\n",
	"/who : list all channel users\n",
	NULL
};

#endif
