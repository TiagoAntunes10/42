/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:42:17 by tialbert          #+#    #+#             */
/*   Updated: 2024/06/10 19:24:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		argument_error(0);
		return (-1);
	}
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (0);
	if (get_args(philo, argv, argc) != 0)
	{
		argument_error(1);
		free(philo);
		return (-1);
	}
	start_philo(philo);
	free(philo->mutex);
	free(philo);
	return (0);
}
