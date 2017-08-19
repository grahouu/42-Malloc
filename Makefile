ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAMEO = libft_malloc
NAME = $(NAMEO)_$(HOSTTYPE).so
NAMELK = $(NAMEO).so
CFLAGS = -Wall -Werror -Wextra -Wconversion -g
SFLAGS =  -shared -Wno-error=unused-command-line-argument
#TESTFLAGS = -ggdb -fsanitize=address -fno-omit-frame-pointer
INCLUDES = -I./inc/

SRC =	src/ft_malloc.c				\
		src/ft_free.c				\
		src/ft_calloc.c				\
		src/merge_freed.c				\
		src/sort_meta_data.c				\
		src/ft_realloc.c			\
		src/new_range.c				\
		src/new_slice.c				\
		src/free_slice.c				\
		src/show_alloc_mem.c	\
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
		src/count_type.c \

OBJ = $(SRC:.c=.o)

TEST0=test_malloc_0.c
TEST1=test_malloc_1.c
TEST2=test_malloc_2.c
TEST3=test_malloc_3.c
TEST4=test_malloc_4.c
TEST5=test_malloc_5.c
TEST6=test_malloc_6.c
TEST7=test_realloc_1.c
TEST8=test_realloc_2.c
TEST9=test_realloc_3.c
TEST10=test_realloc_4.c
TEST11=test_realloc_5.c
TEST12=test_realloc_6.c
TEST13=test_calloc_1.c
TEST_FREE_TINY=test_free_tiny.c
TEST_FREE_SMALL=test_free_small.c
TEST_FREE_LARGE=test_free_large.c
TEST_FREE_ALL=test_free_all.c

all: $(NAME) finish

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@#gcc $(CFLAGS) $(SFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)
	ln -sf $(NAME) $(NAMELK)
	@echo This Job is Done sir !

%.o: %.c 
	@gcc $(CFLAGS) $(TESTFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

cmain_malloc:
	# TEST MALLOC
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

cmain_calloc:
	# TEST CALLOC
	@make -C test/ 1="../$(NAME)" 2="$(TEST13)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST13)"

cmain_free:
	# TEST FREE
	@make -C test/ 1="../$(NAME)" 2="$(TEST_FREE_TINY)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST_FREE_TINY)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST_FREE_SMALL)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST_FREE_SMALL)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST_FREE_LARGE)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST_FREE_LARGE)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST_FREE_ALL)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST_FREE_ALL)"

cmain_realloc:
	# TEST REALLOC
	@make -C test/ 1="../$(NAME)" 2="$(TEST7)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST7)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST8)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST8)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST9)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST9)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST10)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST10)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST11)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST11)"
	@make -C test/ 1="../$(NAME)" 2="$(TEST12)"
	@./test/libftmalloc_test
	@make -C test/ fclean 1="../$(NAME)" 2="$(TEST12)"

test: re cmain_malloc cmain_calloc cmain_free cmain_realloc fclean

test_malloc: re cmain_malloc fclean

test_calloc: re cmain_calloc fclean

test_free: re cmain_free fclean

test_realloc: re cmain_realloc fclean

.PHONY: all build clean fclean re test
