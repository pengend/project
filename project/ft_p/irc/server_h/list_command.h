/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:15:38 by pxia              #+#    #+#             */
/*   Updated: 2015/05/01 18:25:07 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_COMMAND_H
# define LIST_COMMAND_H

#include "irc.h"

typedef struct s_ft
{
	char *cmd;
	char *(*func)(t_client *cli, char **args);
}				t_ft;

t_ft g_cmd[] =
{
//	{"/nick", ft_nick},
	{"/join", ft_join},
//	{"/who", ft_who},
//	{"/msg", ft_msg},
	{NULL, NULL},
};

#endif

