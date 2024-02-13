# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:04:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/13 17:37:44 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

man = philo_/
bon = philo_bonus/

SRC =	${man}main.c \
		${man}ft_parse_param.c \
		${man}philo_functions_utils.c \
		${man}init_all_infos.c   \
		${man}philos_life.c \
		${man}check_if_dead.c \
		${man}free_all_philos.c\

SRC_B =	${bon}main_bonus.c        \
		${bon}init_infos_bonus.c   \
		${bon}error_message_bonus.c \
		${bon}error_parsing_bonus.c  \
		${bon}philo_functions_bonus.c \
		${bon}ft_parse_the_philos_bonus.c \

OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
NAME = philo
NAME_B = philo_bonus
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

bonus : ${NAME_B} clean

%_bonus.o : %_bonus.c ${bon}philosophers_bonus.h
	@cc ${CFLAGS} -c $< -o $@

%.o : %.c ${man}philosophers.h
	@cc ${CFLAGS} -c $< -o $@
	@echo "\033[90mCompiling $< \033[0m"

${NAME} : ${OBJ}
	@cc ${OBJ} -o $@
	@echo "\033[43mLinked Successfully\033[0m"

${NAME_B} : ${OBJ_B}
	@cc ${OBJ_B} -o $@

clean :
	@echo "\033[34m\nCleaned Successfully\n\033[0m"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
