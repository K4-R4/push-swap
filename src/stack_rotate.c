/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:16:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 08:50:56 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "stack.h"

void	stack_rotate(t_stacks *stacks, char sta)
{
	long long		sta_first;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->a))
			return ;
		sta_first = deque_pop_front(&stacks->a);
		deque_push_back(&stacks->a, sta_first);
	}
	else
	{
		if (deque_is_empty(&stacks->b))
			return ;
		sta_first = deque_pop_front(&stacks->b);
		deque_push_back(&stacks->b, sta_first);
	}
}

void	stack_rr(t_stacks *stacks)
{
	stack_rotate(stacks, 'a');
	stack_rotate(stacks, 'b');
}

void	stack_rrotate(t_stacks *stacks, char sta)
{
	long long		sta_last;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->a))
			return ;
		sta_last = deque_pop_back(&stacks->a);
		deque_push_front(&stacks->a, sta_last);
	}
	else
	{
		if (deque_is_empty(&stacks->b))
			return ;
		sta_last = deque_pop_back(&stacks->b);
		deque_push_front(&stacks->b, sta_last);
	}
}

void	stack_rrr(t_stacks *stacks)
{
	stack_rrotate(stacks, 'a');
	stack_rrotate(stacks, 'b');
}
