/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:20:55 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 22:52:37 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "stack.h"

void	stack_rra(t_stacks *stacks)
{
	int		a_last;

	if (deque_is_empty(&stacks->a))
		return ;
	a_last = *deque_pop_back(&stacks->a);
	deque_push_front(&stacks->a, a_last);
}

void	stack_rrb(t_stacks *stacks)
{
	int		b_last;

	if (deque_is_empty(&stacks->b))
		return ;
	b_last = *deque_pop_back(&stacks->b);
	deque_push_front(&stacks->b, b_last);
}

void	stack_rrr(t_stacks *stacks)
{
	stack_rra(stacks);
	stack_rrb(stacks);
}
