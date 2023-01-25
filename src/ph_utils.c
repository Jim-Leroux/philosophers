/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:34:46 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/24 18:34:48 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*element;

	if (element_size > 0 && element_count * element_size
		/ element_size != element_count)
		return (0);
	element = (char *)malloc(element_count * element_size);
	if (element == 0)
		return (0);
	element = memset(element, 0, element_count * element_size);
	return (element);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	negative;

	i = 0;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * negative);
}
