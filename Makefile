# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 13:01:29 by jileroux          #+#    #+#              #
#    Updated: 2023/01/25 18:54:06 by jileroux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
## ARGUMENTS

NAME	=	philosophers
CFLAGS	=	-Wall -Wextra -Werror -g3
CC		=	clang


###################################################
## INCLUDE

INCLUDE_FILES	= 	include/philosophers.h\

###################################################
## SOURCES

SRC_FILES	= 	src/main.c\
				src/init.c\
				src/free.c\
				src/parsing.c\
				src/ph_utils.c

###################################################
## PRINTF

PRINTF_FILES	= 	printf/ft_itoa.c\
					printf/ft_printf.c\
					printf/ft_putnbr.c\
					printf/ft_putnbr_x.c\
					printf/ft_char_str.c

###################################################
## RULES

all: ${NAME}

${NAME}: ${SRC_FILES} ${INCLUDE_FILES} ${PRINTF_FILES}
	${CC} ${CFLAGS} -I ${INCLUDE_FILES} ${PRINTF_FILES} ${SRC_FILES} -o ${NAME}

%.o: %.c
	%{CC} ${CFLAGS} $< -o $@

clean :
	rm -rf *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
