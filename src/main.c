/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:25:39 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/25 18:48:39 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	wait_thread(t_data	*data, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < data->nb_philosophers)
		pthread_join(philosophers[i].thread, NULL);
}

void	*philosopher_routine(void *data_des)
{
	int		left_fork;
	int		right_fork;
	t_data	*data;

	data = (t_data *)data_des;
	while (1)
	{
		ft_printf("%s TIMESTAMP %d is thinking\n", BLUE, data->philosophers->id);
		usleep(data->philosophers->sleep_time);
		left_fork = data->philosophers->id;
		right_fork = (data->philosophers->id + 1) % data->nb_philosophers;
		pthread_mutex_lock(&(data->forks[left_fork]));
		pthread_mutex_lock(&(data->forks[right_fork]));
		ft_printf("%s TIMESTAMP %d is eating\n", BLUE, data->philosophers->id);
		usleep(data->philosophers->eat_time);
		pthread_mutex_unlock(&(data->forks[left_fork]));
		pthread_mutex_unlock(&(data->forks[right_fork]));
		ft_printf("%s TIMESTAMP %d is sleeping\n", BLUE, data->philosophers->id);
		usleep(data->philosophers->sleep_time);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philosopher	*philosophers;

	if (parsing(argc, argv) == 0)
		return (EXIT_FAILURE);
	data = calloc(ft_atoi(argv[1]), sizeof(data));
	philosophers = calloc(ft_atoi(argv[1]), sizeof(t_philosopher));
	if (init_philosopher(argv, data, philosophers, ft_atoi(argv[1])) == 0
		|| init_philosopher(argv, data, data->philosophers,
			ft_atoi(argv[1])) == 0
		|| init_data(data, ft_atoi(argv[1])) == 0)
		return (EXIT_FAILURE);
	pthread_mutex_init(&(data->message_mutex), NULL);
	init_thread(data, philosophers);
	free_all(data, philosophers);
	return (0);
}
