/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:19:39 by tialbert          #+#    #+#             */
/*   Updated: 2024/07/06 10:41:34 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

static int	mutex_lock(t_philo_lst *philo_lst)
{
	long long	t_now;
	t_philo_lst	*lst;

	lst = philo_lst;
	t_now = get_time(philo_lst);
	if (t_now == -1)
		return (-1);
	printf("%lld - %d is thinking\n", t_now, philo_lst->seat);
	if (pthread_mutex_lock(&lst->mutex) != 0)
		return (-1);
	t_now = get_time(philo_lst);
	if (t_now == -1)
		return (-1);
	if (philo_lst->kill != 0)
		return (-1);
	printf("%lld - %d has taken a fork\n", t_now, philo_lst->seat);
	lst = lst->next;
	if (pthread_mutex_lock(&lst->mutex) != 0)
		return (-1);
	philo_lst->eating = 1;
	if (philo_lst->kill != 0)
		return (-1);
	printf("%lld - %d has taken a fork\n", t_now, philo_lst->seat);
	return (0);
}

static int	mutex_unlock(t_philo_lst *philo_lst)
{
	t_philo_lst	*lst;

	philo_lst->eating = 0;
	lst = philo_lst;
	if (pthread_mutex_unlock(&lst->mutex) != 0)
		return (-1);
	lst = philo_lst->next;
	if (pthread_mutex_unlock(&lst->mutex) != 0)
		return (-1);
	return (0);
}

static int	philo_sim(t_philo_lst *philo_lst)
{
	if (mutex_lock(philo_lst) == -1)
		return (-1);
	if (get_eat_time(philo_lst) == -1)
		return (-1);
	if (philo_lst->kill != 0)
		return (-1);
	write_state(&philo_lst, "eat");
	if (mutex_unlock(philo_lst) == -1)
		return (-1);
	if (philo_lst->kill != 0)
		return (-1);
	if (get_eat_time(philo_lst) == -1)
		return (-1);
	write_state(&philo_lst, "sleep");
	if (philo_lst->kill != 0)
		return (-1);
	return (0);
}

void	*run_thread(void *arg)
{
	t_philo_lst		*philo_lst;
	long long		eat_limit;

	philo_lst = (t_philo_lst *) arg;
	pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
	philo_lst->philo_const->queue++;
	pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
	while (philo_lst->philo_cond->start != 1)
		usleep(5);
	eat_limit = philo_lst->philo_const->eat_num;
	if (get_eat_time(philo_lst) == -1)
		return (NULL);
	while (eat_limit-- > 0 || eat_limit < 0)
	{
		if (philo_sim(philo_lst) == -1)
			return (NULL);
		if (eat_limit == 0)
		{
			pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
			philo_lst->philo_cond->death = -1;
			pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
			return (NULL);
		}
	}
	return (NULL);
}

// TODO: Reduce number of lines
void	*watcher(void *arg)
{
	t_philo_lst	*philo_lst;
	int			i;

	philo_lst = (t_philo_lst *) arg;
	while (philo_lst->philo_const->queue < philo_lst->philo_const->philos_num)
		usleep(5);
	pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
	philo_lst->philo_cond->start++;
	pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
	while (philo_lst->philo_cond->death == 0)
	{
		pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
		if (starve_check(philo_lst) == 1 && philo_lst->eating == 0)
			philo_lst->philo_cond->death = philo_lst->seat;
		pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
		if (philo_lst->philo_cond->death == -1)
			return (NULL);
		philo_lst = philo_lst->next;
	}
	i = 0;
	if (get_eat_time(philo_lst) == -1)
		return (NULL);
	printf("%lld - %d died\n", philo_lst->t_after_eat,
		philo_lst->philo_cond->death);
	while (i++ < philo_lst->philo_const->philos_num)
	{
		pthread_mutex_lock(&philo_lst->philo_cond->death_mutex);
		philo_lst->kill++;
		pthread_mutex_unlock(&philo_lst->philo_cond->death_mutex);
		philo_lst = philo_lst->next;
	}
	return (NULL);
}
