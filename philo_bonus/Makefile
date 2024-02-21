SRC =	philosophers.c \
		ft_parse_param.c \
		philo_functions_utils.c \
		ft_init.c   \

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

norm :
	@norminette

clean :
	@echo "\033[34mCleaned Successfully\033[0m"
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
