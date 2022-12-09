MANDATORY_SOURCE =  ft_getargs.c ft_printf.c ft_putbase.c ft_usedfunc.c
BONUS_SOURCE =  ft_getargs_bonus.c ft_printf_bonus.c ft_putbase.c ft_usedfunc.c

MANDATORY_OBJ = ${MANDATORY_SOURCE:.c=.o}
BONUS_OBJ = ${BONUS_SOURCE:.c=.o}

REMOVE = rm -f
CC = cc
APPEND = ar rc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

%.o: %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${MANDATORY_OBJ} ft_printf.h
	${APPEND} ${NAME} ${MANDATORY_OBJ}

clean:
	${REMOVE} ${MANDATORY_OBJ} ${BONUS_OBJ}

bonus: ${BONUS_OBJ} ft_printf_bonus.h
	${APPEND} ${NAME} ${BONUS_OBJ}

fclean: clean
	${REMOVE} ${NAME}

re: fclean all

.PHONY: all clean fclean re