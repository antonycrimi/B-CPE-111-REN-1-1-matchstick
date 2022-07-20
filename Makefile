##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile matchstick
##

SRC	=	./src/game_board.c	\
		./src/get_line.c	\
		./src/display.c	\
		./src/tab.c	\
		./src/ia.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS +=	-Wall -Wextra -I./includes/ -L./lib -lmy

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -L ./lib/my -lmy

clean:
	make fclean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./lib/libmy.a

re:	fclean all
