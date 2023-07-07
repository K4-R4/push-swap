#include "push_swap.h"

t_node	*stk_create_node(void *content)
{
	t_node	*node;
	node = (t_node *)ft_calloc(1, sizeof (t_node));
	node->content = content;
	return (node);
}

void	stk_push_node(t_node **stack, t_node *node)
{
	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
}
