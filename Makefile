

SRC =	main.c        \
		init_infos.c   \
		error_message.c \
		error_parsing.c  \
		philo_functions.c \
		ft_parse_the_philos.c \

OBJ = ${SRC:.c=.o}
HEADER = philosophers.h
NAME = philo
CFLAGS = -Wall -Wextra -Werror


all : ${NAME}

%.o : %.c ${HEADER}
	@echo "Compiling ..."
	@cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@echo "Linking ..."
	@cc $< -o $@
	@echo "Linking DONE"

clean :
	@echo "Cleaned Successfully"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
