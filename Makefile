NAME = libftmalloc.a
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I./inc/

SRC =	src/ft_malloc.c				\
		src/ft_free.c				\
		src/ft_realloc.c			\
		src/new_range.c				\
		src/new_slice.c				\
		src/free_slice.c				\
		src/print_mem_meta_data.c	\
		src/printer.c	\
		src/find_first_none_meta_data.c \
		src/is_slice_in_range.c \
		src/is_range.c \
		src/type_to_str.c \
		src/find_empty_mem_in_range.c \
		src/is_slice_or_free.c \
		src/find_meta_data_by_ptr.c \
		src/find_range_by_meta.c \
		src/is_range_empty.c \
		src/truncate_freed_memory.c \

OBJ = $(SRC:.c=.o)

TEST0=test_malloc_0.c
TEST1=test_malloc_1.c
TEST2=test_malloc_2.c
TEST3=test_malloc_3.c
TEST4=test_malloc_4.c
TEST5=test_malloc_5.c
TEST6=test_malloc_6.c
TEST_FREE=free.c

all: $(NAME) finish

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) 
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

cmain:
	@make -C test/ 1="../$(NAME)" 2="$(TEST0)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST0)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST1)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST1)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST2)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST2)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST3)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST3)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST4)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST4)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST5)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST5)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST6)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST6)"
	# @make -C test/ 1="../$(NAME)" 2="$(TEST_FREE)"
	# ./test/libftmalloc_test
	# @make -C test/ fclean 1="../$(NAME)" 2="$(TEST_FREE)"

test: re cmain fclean

.PHONY: all build clean fclean re test