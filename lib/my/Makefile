##
## EPITECH PROJECT, 2019
## Bistro
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS  =       -I ../../include

AR	=	ar rc

NAME	=	libmy.a

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	cp libmy.a ../

clean:
	rm -rf $(OBJ)
	rm -f *.a
	rm -f ../*.a

fclean:
	rm -rf $(OBJ)

re:
	fclean all
