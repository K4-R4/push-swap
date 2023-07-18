#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "deque.h"
#include "stack.h"
#include "sort.h"

bool	is_valid_arg(char **num_list);
bool	parse_arg(t_stacks *stacks, char *arg);

// For debug only
#include "stdio.h"
void	deque_print_all(t_deque *deque);

#endif
