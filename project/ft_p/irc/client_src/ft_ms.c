/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:25:34 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 17:43:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static void print_sd_mission(t_sd_mission *ms)
{
	char *s;
	char *num;

	num = ft_itoa((int)ms->size * 1.0 / ms->max_size * 100);
	s = ft_join_all(7, " -- ", ms->info.rv, " | file\'s name : ",
					ms->info.name, " | Progress : ", num, " %");
	ft_putstr(s);
	if (ms->stat == WAIT)
		ft_putstr(" | Waiting answer");
	else
	{
		ft_putstr(" | id : ");
		ft_putnbr(ms->info.id);
		ft_putstr(" | Sending");
	}
	ft_putchar('\n');
	free(s);
	free(num);
}

static void print_rv_mission(t_sd_mission *ms)
{
	char *s;
	char *num;

	num = ft_itoa((int)ms->size * 1.0 / ms->max_size * 100);
	s = ft_join_all(7, " -- ", ms->info.sd, " | file\'s name : ",
					ms->info.name, " | Progress : ", num, " % | id : ");
	ft_putstr(s);
	ft_putnbr(ms->info.id);
	if (ms->stat == WAIT)
		ft_putstr(" | Waiting for confirm\n");
	else
		ft_putstr(" | Recving\n");
	free(s);
	free(num);
}

int ft_ms(char **args)
{
	t_sd_mission *tmp;

	(void)args;
	ft_putstr(C_BOLD);
	ft_putstr(" Current sending files :\n");
	tmp = g_sd;
	while (tmp != NULL)
	{
		print_sd_mission(tmp);
		tmp = tmp->next;
	}
	ft_putstr("\n Current recving file :\n");
	tmp = g_rv;
	while (tmp != NULL)
	{
		print_rv_mission(tmp);
		tmp = tmp->next;
	}
	ft_putstr(C_RESET);
	return (1);
}
