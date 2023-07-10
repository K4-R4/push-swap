/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:16:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 22:20:42 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "stack.h"

void	stack_ra(t_stacks *stacks)
{
	int		a_first;

	if (deque_is_empty(&stacks->a))
		return ;
	a_first = *deque_pop_front(&stacks->a);
	deque_push_back(&stacks->a, a_first);
}

void	stack_rb(t_stacks *stacks)
{
	int		b_first;

	if (deque_is_empty(&stacks->b))
		return ;
	b_first = *deque_pop_front(&stacks->b);
	deque_push_back(&stacks->b, b_first);
}

void	stack_rr(t_stacks *stacks)
{
	stack_ra(stacks);
	stack_rb(stacks);
}
