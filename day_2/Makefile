SOURCES = ft_itoa.c \
			ft_split.c \
			main.c \
			parsing.c \
			utils.c \
			check_id.c \

CC = cc
NAME = day_2
CFLAGS = -Wextra -Wall -Werror -I. -g

OBJECTS = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re