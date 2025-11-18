CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_func.c

OBJ = ${SRC:.c=.o}

RM = rm -f
LIBC = ar rcs

all:${NAME}

${NAME}:${OBJ} 
	${LIBC} ${NAME} ${OBJ}

%.o:%.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ} ${objB}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY : clean