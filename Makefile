NAME	= zappy_server

CC	= gcc

RM	= rm -f

SRCS	= server/src/create_map.c		\
	  server/src/delete_and_base_of_map.c	\
	  server/src/generation_of_ressources.c	\
	  server/src/parser_map.c		\
	  server/src/action.c			\
	  src/args_functions.c			\
	  src/command.c				\
	  src/communication_management.c	\
	  src/errors_management.c		\
	  src/func_command.c			\
	  src/incomming_msg.c			\
	  src/interact_management.c		\
	  src/main.c				\
	  src/parser_management.c		\
	  server/src/player.c			\
	  src/str_to_word_array.c		\
	  src/protocol_cmd.c			\
	  src/protocol_cmd2.c			\
	  src/protocol_util.c			\
	  server/src/evolution.c		\
	  src/communication_ia.c



OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -g3 -luuid

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
