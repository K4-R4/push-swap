NAME = push_swap
SRCDIR = $(realpath .)
INCDIR = $(SRCDIR)
OBJDIR = $(SRCDIR)
SRCS = main.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
LIBFT = $(realpath ./libft)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all
