CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=pipex
DEPS = pipex.h
LIBFT = libft/libft.a
SRCS = exec.c main.c utils.c

all: ${NAME}

${NAME}: ${SRCS} ${DEPS} ${LIBFT}
	@${CC} ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME}
	@printf '\033[1;32mPipex compile success!\n\033[0m'

${LIBFT}: 
	@make -C libft

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@rm -rf pipex
	@printf '\033[1;35mDelete pipex\n\033[0m'

re: fclean all

.PHONY:	all clean fclean re
