/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:38:39 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/25 14:30:32 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_all(t_data *data, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < data->nb_philosophers)
		pthread_mutex_destroy(&(data->forks[i]));
	free(philosophers);
	free(data->forks);
	free(data);
}
