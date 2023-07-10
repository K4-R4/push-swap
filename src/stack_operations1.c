/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:44:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/10 22:17:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_sa(t_stacks *stacks)
{
	int		a_first;
	int		a_second;

	if (deque_is_empty(&stacks->a)
		|| stacks->a.sz == 1)
		return ;
	a_first = *deque_pop_front(&stacks->a);
	a_second = *deque_pop_front(&stacks->a);
	deque_push_front(&stacks->a, a_first);
	deque_push_front(&stacks->a, a_second);
}

void	stack_sb(t_stacks *stacks)
{
	int		b_first;
	int		b_second;

	if (deque_is_empty(&stacks->b)
		|| stacks->b.sz == 1)
		return ;
	b_first = *deque_pop_front(&stacks->b);
	b_second = *deque_pop_front(&stacks->b);
	deque_push_front(&stacks->b, b_first);
	deque_push_front(&stacks->b, b_second);
}

void	stack_ss(t_stacks *stacks)
{
	stack_sa(stacks);
	stack_sb(stacks);
}

void	stack_pa(t_stacks *stacks)
{
	int		b_first;

	if (deque_is_empty(&stacks->b))
		return ;
	b_first = *deque_pop_front(&stacks->b);
	deque_push_front(&stacks->a, b_first);
}

void	stack_pb(t_stacks *stacks)
{
	int		a_first;

	if (deque_is_empty(&stacks->a))
		return ;
	a_first = *deque_pop_front(&stacks->a);
	deque_push_front(&stacks->b, a_first);
}
