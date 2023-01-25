/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:18:12 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/25 18:52:44 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TIMES_TO_COUNT	21000

# define NC			"\e[0m"
# define YELLOW		"\e[33m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define BLUE		"\e[34m"
# define VIOLET		"\e[35m"

# define BYELLOW	"\e[1;33m"
# define BRED		"\e[1;31m"
# define BGREEN		"\e[1;32m"
# define BBLUE		"\e[1;34m"
# define BVIOLET	"\e[1;35m"

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

enum e_state{
	THINKING,
	EATING,
	HUNGRY
};

typedef struct s_philosopher
{
	int			id;
	int			state;
	int			eat_time;
	int			die_time;
	int			sleep_time;
	int			eating_count;
	pthread_t	thread;
}	t_philosopher;

typedef struct s_data
{
	int				nb_philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message_mutex;
	pthread_t		main_thread;
	t_philosopher	*philosophers;
}	t_data;

int		ft_atoi(const char *nptr);
int		parsing(int argc, char **argv);

int		init_thread(t_data *data, t_philosopher *philosophers);
int		init_data(t_data *data, int nb_philosophers);
int		init_philosopher(char **argv, t_data *data, t_philosopher *philosopher,
			int nb_philosophers);

void	*philosopher_routine(void *data);

void	free_all(t_data *data, t_philosopher *philosophers);

#endif
