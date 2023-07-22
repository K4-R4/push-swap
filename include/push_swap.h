#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "deque.h"
#include "stack.h"
#include "sort.h"

bool	is_valid_arg(char **num_list);
bool	parse_arg(t_stacks *stacks, int argc, char **argv);
long long	convert_idx_to_ops(long long idx, long long sta_sz);
long long	my_abs(long long nbr);
long long	my_min(long long a, long long b);

// For debug only
#include "stdio.h"
void	deque_print_all(t_deque *deque);

#endif
