/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:44:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/17 08:56:35 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stacks *stacks, char sta)
{
	long long		sta_first;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->b))
			return ;
		sta_first = deque_pop_front(&stacks->b);
		deque_push_front(&stacks->a, sta_first);
	}
	else
	{
		if (deque_is_empty(&stacks->a))
			return ;
		sta_first = deque_pop_front(&stacks->a);
		deque_push_front(&stacks->b, sta_first);
	}
}
