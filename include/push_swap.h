#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*nex;
	void	*content;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
}				t_stack;

#endif
