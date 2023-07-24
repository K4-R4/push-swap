NAME = push_swap
SRC_DIR = ./src/
PARSER_DIR = $(SRC_DIR)parser/
DEQUE_DIR = $(SRC_DIR)deque/
STACK_DIR = $(SRC_DIR)stack/
SORT_DIR = $(SRC_DIR)sort/
SRCS = main.c \
		push_swap_utils.c
PARSER = parse_args.c \
		validate_args.c
DEQUE = deque_push_pop.c \
		deque_search.c \
		deque_utils.c
STACK = stack_swap.c \
		stack_push.c \
		stack_rotate.c \
		stack_rrotate.c \
		stack_utils.c
SORT = sort.c \
		sort_few_elements.c \
		sort_many_elements.c \
		simulate_ops.c \
		execute_ops.c \
		execute_ops_helper.c
OBJS += $(addprefix $(SRC_DIR), $(SRCS:.c=.o))
OBJS += $(addprefix $(PARSER_DIR), $(PARSER:.c=.o))
OBJS += $(addprefix $(DEQUE_DIR), $(DEQUE:.c=.o))
OBJS += $(addprefix $(STACK_DIR), $(STACK:.c=.o))
OBJS += $(addprefix $(SORT_DIR), $(SORT:.c=.o))

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

re: fclean all
