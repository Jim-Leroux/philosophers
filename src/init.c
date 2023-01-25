/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:59:12 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/25 18:43:54 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_thread(t_data	*data, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < data->nb_philosophers)
		pthread_create(&(philosophers[i].thread), NULL, philosopher_routine,
			&philosophers[i]);
	return (1);
}

int	init_philosopher(char **argv, t_data	*data, t_philosopher *philosopher,
		int nb_philosophers)
{
	int	i;

	if (philosopher == NULL)
		return (write(2, "Error : calloc philosopher struct\n", 34), 0);
	i = -1;
	data->nb_philosophers = nb_philosophers;
	while (++i < nb_philosophers)
	{
		philosopher[i].id = i;
		philosopher->die_time = ft_atoi(argv[2]);
		philosopher->eat_time = ft_atoi(argv[3]);
		philosopher->sleep_time = ft_atoi(argv[4]);
		if (argv[5] != 0)
			philosopher->eating_count = ft_atoi(argv[5]);
	}
	return (1);
}

int	init_data(t_data *data, int nb_philosophers)
{
	int	i;

	data->nb_philosophers = nb_philosophers;
	data->forks = calloc(nb_philosophers, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < nb_philosophers)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->message_mutex, NULL);
	if (data == NULL || data->forks == NULL)
		return (write(2, "Error : calloc data struct\n", 27), 0);
	return (1);
}
