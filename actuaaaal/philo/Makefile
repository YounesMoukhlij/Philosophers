# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:04:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/22 19:11:30 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		ft_parse_param.c \
		philo_functions_utils.c \
		init_all_infos.c   \
		philos_life.c \
		check_if_dead.c \
		free_all_philos.c\

OBJ = ${SRC:.c=.o}
NAME = philo
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

all : ${NAME} clean

%.o : %.c philosophers.h
	@cc ${CFLAGS} -c $< -o $@
	@echo "\033[90mCompiling $< \033[0m"

${NAME} : ${OBJ}
	@cc ${CFLAGS} ${OBJ} -o $@
	@echo "\033[43mLinked Successfully\033[0m"

norm :
	@norminette

clean :
	@echo "\033[34mCleaned Successfully\033[0m"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
