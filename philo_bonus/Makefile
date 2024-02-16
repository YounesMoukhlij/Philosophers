# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:04:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/16 21:16:11 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main_bonus.c            \
		philos_life_bonus.c      \
		check_if_dead_bonus.c     \
		init_all_infos_bonus.c     \
		ft_parse_param_bonus.c      \
		free_all_philos_bonus.c      \
		philo_functions_utils_bonus.c \

OBJ = ${SRC:.c=.o}
NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c philosophers_bonus.h
	@cc ${CFLAGS} -c $< -o $@
	@echo "\033[90mCompiling $< \033[0m"

${NAME} : ${OBJ}
	@cc ${OBJ} -o $@
	@echo "\033[43mLinked Successfully\033[0m"

clean :
	@echo "\033[34mCleaned Successfully\033[0m"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
