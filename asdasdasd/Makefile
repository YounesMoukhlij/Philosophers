# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 16:52:46 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/17 17:50:48 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main_bonus.c \
		ft_atoi_bonus.c \
		ft_calloc_bonus.c \
		ft_free_all_bonus.c \
		ft_get_args_bonus.c \
		ft_get_time_bonus.c \
		ft_init_philos_bonus.c \
		ft_init_sem_bonus.c \
		ft_philo_actions_bonus.c \
		ft_print_msg_bonus.c \
		ft_puterr_bonus.c \
		ft_strlen_bonus.c \
		
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
