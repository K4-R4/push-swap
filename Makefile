NAME = push_swap
SRCDIR = ./src/
OBJDIR = $(SRCDIR)
SRCS = main.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
TEST_SRCS = test.c deque.c deque_sub.c
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

test: $(TEST_OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LDFLAGS) -o $@

re: fclean all
