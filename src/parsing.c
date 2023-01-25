/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:15:15 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/24 17:06:52 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	parsing(int argc, char **argv)
{
	if (argc < 5)
		return (write(2, "Missing arguments\n", 18), 0);
	if (ft_atoi(argv[1]) <= 0)
		return (write(2, "Invalid number of philosophers\n", 31), 0);
	return (1);
}
