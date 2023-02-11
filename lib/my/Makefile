##
## EPITECH PROJECT, 2022
## JAM
## File description:
## Makefile
##

SRC			=	my_strlen.c	\
				my_putstr.c	\
				my_strcmp.c	\
				my_getnbr.c	\
				my_intlen.c	\
				my_int_to_str.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

W_FLAGS		=	-W -Wall -Wextra

INC_FLAG	=	-I../../include

all:			$(OBJ)
		gcc $(W_FLAGS) -c $(SRC) $(INC_FLAGS)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:			clean
		rm -f ../$(NAME) *.vgcore

re:				fclean all

debug:			fclean
		gcc $(W_FLAGS) -c $(SRC) $(INC_FLAGS) -g
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../
