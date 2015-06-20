/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 20:37:37 by pxia              #+#    #+#             */
/*   Updated: 2015/06/12 21:09:02 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; /* Création du mutex */

void *thread_1(void *arg)
{
	(void)arg;
	while (1)
	{
		printf("T1 not locked\n");
		pthread_mutex_lock(&mutex);
		printf("T1 locked\n");
		sleep(2);
		printf("\n");
		pthread_mutex_unlock(&mutex);
	}
}

void *thread_2(void *arg)
{
	(void)arg;
	while (1)
	{
		printf("T2 not locked\n");
		pthread_mutex_lock(&mutex);
		printf("T2 locked\n");
		sleep(2);
		printf("\n");
		pthread_mutex_unlock(&mutex);		
	}
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, thread_1, NULL);
	pthread_create(&t2, NULL, thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);

}
