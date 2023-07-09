#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_deque
{
    long long  sz;
	long long	front;
	long long	back;
	int	*buffer;
}				t_deque;

typedef struct s_stacks
{
	t_deque a;
	t_deque b;
}				t_stacks;

#endif
