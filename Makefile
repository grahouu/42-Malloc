NAME = malloc
VERSION = 1.0.4
CFLAGS = -Wall -Werror -Wextra -g

SRC =	test/main.c					\

OBJ = $(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS) -lpthread
	@echo This Job is Done sir !

%.o: %.c inc/ft_malloc.h
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v