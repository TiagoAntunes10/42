/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:19:39 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/29 16:25:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

// TODO: Protect mutex locks/unlocks
static int	mutex_lock(t_philo_lst *philo_lst)
{
	long		t_now;
	t_philo_lst	*lst;

	lst = philo_lst;
	if (philo_lst->kill != 0)
		return (-1);
	t_now = get_time(philo_lst);
	if (t_now == -1)
		return (-1);
	printf("%ld - %d is thinking\n", t_now, philo_lst->seat);
	while (lst->mutex_struct->lock == 1)
	{
		if (starve_check(lst) == 1)
		{
			pthread_mutex_lock(&lst->philo_cond->death_mutex);
			lst->philo_cond->death = lst->seat;
			pthread_mutex_unlock(&lst->philo_cond->death_mutex);
			return (-1);
		}
	}
	pthread_mutex_lock(&lst->mutex_struct->mutex);
	lst->mutex_struct->lock = 1;
	t_now = get_time(philo_lst);
	if (t_now == -1)
		return (-1);
	printf("%ld - %d has taken a fork\n", t_now, philo_lst->seat);
	lst = lst->next;
	while (lst->mutex_struct->lock == 1)
	{
		if (starve_check(lst) == 1)
		{
			pthread_mutex_lock(&lst->philo_cond->death_mutex);
			lst->philo_cond->death = lst->seat;
			pthread_mutex_unlock(&lst->philo_cond->death_mutex);
			return (-1);
		}
	}
	pthread_mutex_lock(&lst->mutex_struct->mutex);
	lst->mutex_struct->lock = 1;
	printf("%ld - %d has taken a fork\n", t_now, philo_lst->seat);
	return (0);
}

static void	mutex_unlock(t_philo_lst *philo_lst)
{
	t_philo_lst	*lst;

	lst = philo_lst;
	lst->mutex_struct->lock = 0;
	pthread_mutex_unlock(&philo_lst->mutex_struct->mutex);
	lst = philo_lst->next;
	lst->mutex_struct->lock = 0;
	pthread_mutex_unlock(&philo_lst->mutex_struct->mutex);
}

void	*run_thread(void *arg)
{
	t_philo_lst		*philo_lst;
	long			t_now;

	philo_lst = (t_philo_lst *) arg;
	philo_lst->t_after_eat = get_time(philo_lst);
	if (philo_lst->t_after_eat == -1)
		return (NULL);
	while (philo_lst->philo_const->eat_num > 0 || philo_lst->philo_const->eat_num-- < 0)
	{
		if (mutex_lock(philo_lst) == -1)		
			return (NULL);
		t_now = get_time(philo_lst);
		if (t_now == -1)
			return (NULL);
		printf("%ld - %d is eating\n", t_now, philo_lst->seat);
		usleep(philo_lst->philo_const->t_eat * 1000);
		mutex_unlock(philo_lst);
		philo_lst->t_after_eat = get_time(philo_lst);
		if (philo_lst->t_after_eat == -1)
			return (NULL);
		printf("%lld - %d is sleeping\n", philo_lst->t_after_eat, philo_lst->seat);
		usleep(philo_lst->philo_const->t_sleep * 1000);
	}
	return (NULL);
}

void	*watcher(void *arg)
{
	t_philo_lst	*philo_lst;
	int			i;
	long		t_now;

	philo_lst = (t_philo_lst *) arg;
	while (philo_lst->philo_cond->death == 0)
	{
		pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
		pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
	}
	i = 0;
	t_now = get_time(philo_lst);
	if (t_now == -1)
		return (NULL);
	printf("%ld - %d died\n", t_now, philo_lst->philo_cond->death);
	while (i++ < philo_lst->philo_const->philos_num)
	{
		pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
		philo_lst->kill++;
		pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
		philo_lst = philo_lst->next;
	}
	return (NULL);
}

void	start_philo(t_philo_const *philo)
{
	pthread_t		*thread;
	t_philo_lst		*philo_lst;
	int				i;

	thread = malloc(sizeof(pthread_t) * philo->philos_num + 1);
	if (thread == NULL)
		return ;
	philo_lst = create_lst(philo);
	if (philo_lst == NULL)
		return ;
	start_mutex(philo_lst);
	i = 0;
	if (pthread_create(&thread[i++], NULL, &watcher, (void *) philo_lst) != 0)
		return ;
	if (get_init_time(philo_lst) == -1)
		return ;
	while (i <= philo->philos_num)
	{
		if (pthread_create(thread + i, NULL, &run_thread, (void *) philo_lst) != 0)
			return ;
		i++;
		philo_lst = philo_lst->next;
	}
	i = 0;
	while (i <= philo->philos_num)
	{
		if (pthread_join(thread[i++], NULL) != 0)
			return ;
	}
	end_lst(philo_lst);
}
