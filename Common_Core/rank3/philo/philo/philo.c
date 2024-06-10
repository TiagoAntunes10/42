/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:19:39 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/10 21:50:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

static void	mutex_lock(t_philo *philo)
{
	if (philo->i == philo->philos_num)
	{
		pthread_mutex_lock(&philo->mutex[philo->i - 1]);
		pthread_mutex_lock(&philo->mutex[0]);
	}
	else
	{
		pthread_mutex_lock(&philo->mutex[philo->i]);
		pthread_mutex_lock(&philo->mutex[philo->i - 1]);
	}
}

static void	mutex_unlock(t_philo *philo)
{
	if (philo->i == philo->philos_num - 1)
	{
		pthread_mutex_unlock(&philo->mutex[philo->i - 1]);
		pthread_mutex_unlock(&philo->mutex[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->mutex[philo->i]);
		pthread_mutex_unlock(&philo->mutex[philo->i - 1]);
	}
}

void	*run_thread(void *arg)
{
	t_philo			*philo;
	struct timeval	t_init;
	struct timeval	t_now;

	philo = (t_philo *) arg;
	if (gettimeofday(&t_init, NULL) != 0)
		return (NULL);
	while (philo->eat_num > 0 || philo->eat_num-- < 0)
	{
		mutex_lock(philo);
		if (gettimeofday(&t_now, NULL) != 0)
			return (NULL);
		printf("%ld - %d has taken a fork\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		if (gettimeofday(&t_now, NULL) != 0)
			return (NULL);
		printf("%ld - %d is eating\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		usleep(philo->t_eat * 1000);
		mutex_unlock(philo);
		if (gettimeofday(&t_now, NULL) != 0)
			return (NULL);
		printf("%ld - %d is sleeping\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		usleep(philo->t_sleep * 1000);
		if (gettimeofday(&t_now, NULL) != 0)
			return (NULL);
		printf("%ld - %d is thinking\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
	}
	return (NULL);
}

void	start_philo(t_philo *philo)
{
	pthread_t			*thread;

	thread = malloc(sizeof(pthread_t) * philo->philos_num);
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->philos_num);
	philo->i = 0;
	while (philo->i < philo->philos_num)
		pthread_mutex_init(&philo->mutex[philo->i++], NULL);
	philo->i = 0;
	while (philo->i < philo->philos_num)
	{
		if (pthread_create(&thread[philo->i++], NULL, &run_thread, (void *) philo) != 0)
			return ;
	}
	philo->i = 0;
	while (philo->i < philo->philos_num)
	{
		if (pthread_join(thread[philo->i++], NULL) != 0)
			return ;
	}
	philo->i = 0;
	while (philo->i < philo->philos_num)
		pthread_mutex_destroy(&philo->mutex[philo->i++]);
}
