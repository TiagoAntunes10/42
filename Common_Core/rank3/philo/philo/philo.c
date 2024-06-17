/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:19:39 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/16 21:33:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"
int	sum = 0;

static void	mutex_lock(t_philo_lst *philo_lst)
{
	pthread_mutex_lock(&philo_lst->mutex);
	philo_lst = philo_lst->next;
	pthread_mutex_lock(&philo_lst->mutex);
}

static void	mutex_unlock(t_philo_lst *philo_lst)
{
	pthread_mutex_unlock(&philo_lst->mutex);
	philo_lst = philo_lst->next;
	pthread_mutex_unlock(&philo_lst->mutex);
}

void	*run_thread(void *arg)
{
	t_philo_lst			*philo_lst;
	// struct timeval	t_init;
	// struct timeval	t_now;

	philo_lst = (t_philo_lst *) arg;
	mutex_lock(philo_lst);
	sum += philo_lst->seat;
	printf("sum: %d\n", sum);
	printf("Thread %d\n", philo_lst->seat);
	mutex_unlock(philo_lst);
	// if (gettimeofday(&t_init, NULL) != 0)
	// 	return (NULL);
	// while (philo->eat_num > 0 || philo->eat_num-- < 0)
	// {
		// if (gettimeofday(&t_now, NULL) != 0)
		// 	return (NULL);
		// printf("%ld - %d has taken a fork\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		// if (gettimeofday(&t_now, NULL) != 0)
		// 	return (NULL);
		// printf("%ld - %d is eating\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		// usleep(philo->t_eat * 1000);
		// if (gettimeofday(&t_now, NULL) != 0)
		// 	return (NULL);
		// printf("%ld - %d is sleeping\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
		// usleep(philo->t_sleep * 1000);
		// if (gettimeofday(&t_now, NULL) != 0)
		// 	return (NULL);
		// printf("%ld - %d is thinking\n", (t_now.tv_usec - t_init.tv_usec) / 1000, philo->i);
	// }
	return (NULL);
}

void	start_philo(t_philo_const *philo)
{
	pthread_t	*thread;
	t_philo_lst	*philo_lst;
	int			i;

	thread = malloc(sizeof(pthread_t) * philo->philos_num);
	if (thread == NULL)
		return ;
	philo_lst = create_lst(philo);
	if (philo_lst == NULL)
		return ;
	start_mutex(philo_lst);
	i = 0;
	while (i < philo->philos_num)
	{
		printf("Thread %d started\n", i + 1);
		if (pthread_create(thread + i, NULL, &run_thread, (void *) philo_lst) != 0)
			return ;
		i++;
		philo_lst = philo_lst->next;
	}
	i = 0;
	while (i < philo->philos_num)
	{
		if (pthread_join(thread[i++], NULL) != 0)
			return ;
		printf("Thread %d ended\n", i);
	}
	end_lst(philo_lst);
}
