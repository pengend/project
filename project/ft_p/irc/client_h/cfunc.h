/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfunc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 17:51:39 by pxia              #+#    #+#             */
/*   Updated: 2015/05/27 14:57:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFUNC_H
# define CFUNC_H

# include "client.h"

typedef struct	s_func
{
	char		*name;
	int			(*func)(char **args);
}				t_func;

t_func g_func[]=
{
	{"file", ft_send_file},
	{"confirm", ft_confirm},
	{"ms", ft_ms},
	{NULL, NULL}
};

#endif

