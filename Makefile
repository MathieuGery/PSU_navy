##
## EPITECH PROJECT, 2018
## mathieu gery
## File description:
## Makefile for matchstick
##

SRC	=	main.c				\
		src/server.c			\
		src/client.c			\
		src/map.c			\
		src/pars_map.c			\
		src/pars_map_2.c		\
		src/usage.c			\
		src/print_game.c		\
		src/check.c			\
		src/pid.c			\
		src/attack.c			\
		src/send.c			\
		src/win.c			\
		src/error_gesture.c		\
		src/place_boats.c

NAME	=	navy

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -g -o $(NAME) $(SRC) -Iinclude -Llib/my -lmy -Wall -Wextra

clean:
	make clean -C lib/my

fclean:	clean
	rm -rf $(NAME)
	make fclean -C lib/my

re:	fclean all
