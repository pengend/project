
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
	{"file", ft_file},
	{NULL, NULL}
};
