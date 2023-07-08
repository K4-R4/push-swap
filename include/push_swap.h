#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_deque
{
	int	top;
	int	bottom;
	int	*buffer;
}				t_deque;

typedef struct s_stacks
{
	t_deque a;
	t_deque b;
}				t_stacks;

#endif
