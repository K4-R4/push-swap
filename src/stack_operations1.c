/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:44:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/16 18:48:00 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stacks *stacks, char sta)
{
	int		sta_first;
	int		sta_second;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->a)
			|| stacks->a.sz == 1)
			return ;
		sta_first = *deque_pop_front(&stacks->a);
		sta_second = *deque_pop_front(&stacks->a);
		deque_push_front(&stacks->a, sta_first);
		deque_push_front(&stacks->a, sta_second);
	}
	else
	{
		if (deque_is_empty(&stacks->b)
			|| stacks->b.sz == 1)
			return ;
		sta_first = *deque_pop_front(&stacks->b);
		sta_second = *deque_pop_front(&stacks->b);
		deque_push_front(&stacks->b, sta_first);
		deque_push_front(&stacks->b, sta_second);
	}
}

void	stack_ss(t_stacks *stacks)
{
	stack_swap(stacks, 'a');
	stack_swap(stacks, 'b');
}

void	stack_push(t_stacks *stacks, char sta)
{
	int		sta_first;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->b))
			return ;
		sta_first = *deque_pop_front(&stacks->b);
		deque_push_front(&stacks->a, sta_first);
	}
	else
	{
		if (deque_is_empty(&stacks->a))
			return ;
		sta_first = *deque_pop_front(&stacks->a);
		deque_push_front(&stacks->b, sta_first);
	}
}

void	stack_rotate(t_stacks *stacks, char sta)
{
	int		sta_first;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->a))
			return ;
		sta_first = *deque_pop_front(&stacks->a);
		deque_push_back(&stacks->a, sta_first);
	}
	else
	{
		if (deque_is_empty(&stacks->b))
			return ;
		sta_first = *deque_pop_front(&stacks->b);
		deque_push_back(&stacks->b, sta_first);
	}
}

void	stack_rr(t_stacks *stacks)
{
	stack_rotate(stacks, 'a');
	stack_rotate(stacks, 'b');
}
