##
## EPITECH PROJECT, 2022
## JAM
## File description:
## Makefile
##

SRC				=	src/utilities/check_closing_event.c	\
					src/destroy_epi_jam.c				\
					src/set_struct.c					\
					src/display_elements.c				\
					src/render_elements.c				\
					src/play/waste_bags.c				\
					src/play/play.c						\
					src/stats/all_time_best_score.c		\
					src/stats/stats.c					\
					src/credits/credits.c				\
					src/title_screen/buttons.c			\
					src/title_screen/title_screen.c		\
					src/epi_jam.c						\
					src/main.c

OBJ				=	$(SRC:.c=.o)

NAME			=	epi_jam

W_FLAGS			=	-W -Wall -Wextra

INC_LIB_FLAGS	=	-I./include -L./lib -lmy	\
					-lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

all:
		@make -s -C lib/my/
		@gcc $(W_FLAGS) -o $(NAME) $(SRC) $(INC_LIB_FLAGS)

clean:
		@make -s clean -C lib/my/
		@rm -f $(OBJ)

fclean:				clean
		@make -s fclean -C lib/my/
		@rm -f $(NAME) vgcore.*

re:					fclean all
					@make -s re -C lib/my/

debug:				fclean
		@make -s debug -C lib/my/
		@gcc $(W_FLAGS) -o $(NAME) $(SRC) $(INC_LIB_FLAGS) -g
