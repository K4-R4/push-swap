NAME = push_swap
SRCDIR = ./src/
OBJDIR = $(SRCDIR)
SRCS = main.c \
		parse_args.c \
		validate_args.c \
		deque_core.c \
		deque_utils.c \
		stack_swap.c \
		stack_push.c \
		stack_rotate.c \
		stack_utils.c \
		sort.c \
		sort_few_elements.c \
		sort_many_elements.c \
		simulate_ops.c \
		manage_ops.c \
		debug.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

TEST_SRCS = deque_core.c \
		deque_utils.c \
		stack_swap.c \
		stack_push.c \
		stack_rotate.c
TEST_OBJS = $(addprefix $(OBJDIR), $(TEST_SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./include/ -I ./libft/include/
LDFLAGS = -L libft -l ft
LIBFT = $(realpath ./libft)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	# $(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(INCLUDE)
	gcc -fsanitize=address $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(INCLUDE)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

test: testc $(TEST_OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) test.c $(TEST_OBJS) $(INCLUDE) $(LDFLAGS) -o $@
	./test

testc:
	$(RM) test $(wildcard ./src/*.o)

re: fclean all
