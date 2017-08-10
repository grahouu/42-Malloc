NAME = libftmalloc_test
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I../inc/

LIB = $1

SRC = $2

OBJ = $(SRC:.c=.o)

all: $(NAME) finish

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIB) 
	@echo This Job is Done sir !

%.o: %.c 
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re