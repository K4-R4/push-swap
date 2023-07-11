#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "stack.h"
#include "deque.h"

bool	is_valid_arg(char **num_list);
bool	parse_arg(t_stacks *stacks, char *arg);
long long	*get_lis(t_stacks *stacks, long long *length);

#endif
