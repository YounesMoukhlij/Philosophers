# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:39:00 by youmoukh          #+#    #+#              #
#    Updated: 2024/02/20 17:48:40 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo_functions_utils_bonus.c \
	  ft_parse_param_bonus.c  \
	  philosophers_bonus.c  \
	  philo_life_bonus.c  \
	  init_all_infos_bonus.c   \

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

norm :
	@norminette

clean :
	@echo "\033[34mCleaned Successfully\033[0m"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
