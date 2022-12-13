##
## EPITECH PROJECT, 2020
## B-YEP-410-MAR-4-1-zappy-romain1.meunier
## File description:
## Makefile
##

NAME   = zappy_gui

SRC    = src/SFML/mainSfml.cpp\
		 src/SFML/menu.cpp\
		 src/SFML/setting.cpp\
		 src/SFML/game.cpp\
		 src/SFML/mapzappy.cpp\
		 src/CLI/cli.cpp

OBJ	   = $(SRC:.cpp=.o)

SFML_FLAGS =  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

ERROR_FLAGS = -Wall -Wextra -Werror

all:     $(NAME)

$(NAME):  $(OBJ)
		g++ -o   $(NAME) $(OBJ) $(ERROR_FLAGS) $(SFML_FLAGS)
		rm -f $(OBJ)

	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)

re: fclean all