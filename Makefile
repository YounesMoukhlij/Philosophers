# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:53:30 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/09 14:27:25 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

man = philo/
bon = philo_bonus/

SRC =	${man}main.c        \
		${man}init_all_infos.c   \
		${man}philo_functions_utils.c \
		${man}ft_parse_param.c \
		${man}philos_life.c \

SRC_B =	${bon}main_bonus.c        \
		${bon}init_infos_bonus.c   \
		${bon}error_message_bonus.c \
		${bon}error_parsing_bonus.c  \
		${bon}philo_functions_bonus.c \
		${bon}ft_parse_the_philos_bonus.c \

OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
HEADER = philosophers.h
HEADER_B = philo_bonus/philosophers_bonus.h
NAME = mmmm
NAME_B = bbbb
CFLAGS = -Wall -Wextra -Werror

all : ${NAME} clean play

bonus : ${NAME_B}

play :
	@./mmmm 4 30 33 56 3

%_bonus.o : %_bonus.c ${bon}philosophers_bonus.h
	@cc ${CFLAGS} -c $< -o $@

%.o : %.c ${HEADER}
	@cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@cc ${OBJ} -o $@

${NAME_B} : ${OBJ_B}
	@cc ${OBJ_B} -o $@

clean :
	@echo "Cleaned Successfully\n"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
