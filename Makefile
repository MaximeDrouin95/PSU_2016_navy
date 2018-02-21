##
## Makefile for Makefile in /home/alkoleek/PSU_2016_minishell1
##
## Made by Maxime DROUIN
## Login   <alkoleek@epitech.net>
##
## Started on  Fri Jan 20 02:27:55 2017 Maxime DROUIN
## Last update Sun Jan 22 13:06:07 2017 Maxime DROUIN
##

CC	= gcc -I ./include/

LDFLAGS	= -L./lib -lgnl

RM	= rm -f

NAME	= navy

SRCS	= client.c		\
	  error.c		\
	  converter.c		\
	  correct.c		\
          direction.c		\
	  do_attack.c		\
	  help.c		\
	  load_map.c		\
	  main.c		\
	  map_testers.c		\
	  my_getnbr.c		\
	  my_putchar.c		\
	  my_putnbr.c		\
	  my_putstr.c		\
	  my_revstr.c		\
	  my_showtab.c		\
	  my_strcapitalize.c	\
	  my_strcmp.c		\
	  my_str_isnum.c	\
	  my_strlen.c		\
	  parse_args.c		\
	  navy_actions.c	\
	  navy_signal.c		\
	  printer.c		\
	  put_ship.c		\
	  server.c


OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
