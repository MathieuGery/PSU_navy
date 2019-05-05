##
## EPITECH PROJECT, 2017
## Makefile libmy.a
## File description:
## mathieu gery
##

SRC	=	my_getnbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		get_next_line.c	\
		str_cmp.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		int_to_char.c	\
		str_to_word_array.c

CFLAGS	+=	-I../../include/ -g

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
