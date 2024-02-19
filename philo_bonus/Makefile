# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:39:00 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/19 19:57:13 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo_functions_utils.c \
	  ft_parse_param.c  \
	  philosophers.c  \
	  philo_life.c  \
	  ft_init.c   \

OBJ = ${SRC:.c=.o}
NAME = philo_bonus
HEADER = philosopher_bonus.h
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c ${HEADER}
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
