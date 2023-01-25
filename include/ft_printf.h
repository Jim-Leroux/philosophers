/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:45 by jileroux          #+#    #+#             */
/*   Updated: 2022/05/26 16:24:11 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		main(int argc, char **argv);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_p(unsigned long long int nbr, char *base);
int		ft_printnbr(int n);
char	*ft_itoa(int n);
int		ft_unsigned_int(unsigned int chara);
int		ft_printx(int nbr);
int		ft_print_x(int nbr);
int		ft_putnbr_x(unsigned int n, char *base);
int		ft_check(unsigned long long int nbr, char *base);

#endif
