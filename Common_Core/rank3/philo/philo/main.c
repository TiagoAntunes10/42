/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:42:17 by tialbert          #+#    #+#             */
/*   Updated: 2024/07/06 10:38:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

// TODO: Reduce number of lines
static void	start_philo(t_philo_lst **philo_lst)
{
	pthread_t		*thread;
	int				i;

	thread = malloc(sizeof(pthread_t) * (*philo_lst)->philo_const->philos_num + 1);
	if (thread == NULL)
		return ;
	i = 0;
	if (pthread_create(&thread[i++], NULL, &watcher, (void *) (*philo_lst)) != 0)
		return (free(thread));
	if (get_init_time(philo_lst) == -1)
		return (free(thread));
	while (i <= (*philo_lst)->philo_const->philos_num)
	{
		if (pthread_create(thread + i, NULL,
				&run_thread, (void *) (*philo_lst)) != 0)
			return (free(thread));
		i++;
		*philo_lst = (*philo_lst)->next;
	}
	i = 0;
	while (i <= (*philo_lst)->philo_const->philos_num)
	{
		if (pthread_join(thread[i++], NULL) != 0)
			return (free(thread));
	}
	return (free(thread));
}

int	main(int argc, char **argv)
{
	t_philo_const	*philo;
	t_philo_lst		*philo_lst;

	if (argc < 5 || argc > 6)
	{
		argument_error(0);
		return (-1);
	}
	philo = malloc(sizeof(t_philo_const));
	if (philo == NULL)
		return (0);
	philo->queue = 0;
	if (get_args(philo, argv, argc) != 0)
	{
		argument_error(1);
		free(philo);
		return (-1);
	}
	philo_lst = create_lst(philo);
	if (philo_lst == NULL)
		return (end_lst(philo_lst));
	start_philo(&philo_lst);
	return (end_lst(philo_lst));
}
