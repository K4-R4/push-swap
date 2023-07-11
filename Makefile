NAME = push_swap
SRCDIR = ./src/
OBJDIR = $(SRCDIR)
SRCS = main.c deque1.c deque2.c stack_operations1.c \
	   stack_operations2.c stack_operations3.c \
	   parse_args.c validate_args.c lis.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
TEST_SRCS = deque1.c deque2.c stack_operations1.c \
		stack_operations2.c stack_operations3.c
TEST_OBJS = $(addprefix $(OBJDIR), $(TEST_SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./include/ -I ./libft/include/
LDFLAGS = -L libft -l ft
LIBFT = $(realpath ./libft)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(INCLUDE)

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
