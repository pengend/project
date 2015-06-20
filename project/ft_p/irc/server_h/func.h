/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:54:36 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 20:17:16 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "irc.h"

typedef struct s_func
{
	char *name;
	int (*func)(t_client *client, int cli, char **args, int *number);
}				t_func;

t_func g_func[]=
{
	{"nick", ft_nick},
	{"join", ft_join},
	{"leave", ft_leave},
	{"who", ft_who},
	{"help", ft_help},
	{"msg", ft_msg},
	{"time", ft_time},
	{"quit", ft_quit},
	{NULL, NULL}
};

#endif
