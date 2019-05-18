##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= my_screensaver

CC	= gcc

RM	= rm -f

SRC	= *.c

OBJ	= $(SRC:.c=.o)

FLAG	= -l csfml-graphics -l csfml-system

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(FLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re