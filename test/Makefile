NAME = libftmalloc_test
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I../inc/

LIB = $1

SRC = $2

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c 
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

.PHONY: all build clean fclean re