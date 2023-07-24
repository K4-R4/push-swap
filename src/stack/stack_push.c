/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:44:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/23 17:22:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_pa(t_stacks *stacks)
{
	long long		sta_first;

	if (deque_is_empty(&stacks->b))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "pa\n");
	sta_first = deque_pop_front(&stacks->b);
	deque_push_front(&stacks->a, sta_first);
}

void	stack_pb(t_stacks *stacks)
{
	long long		sta_first;

	if (deque_is_empty(&stacks->a))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "pb\n");
	sta_first = deque_pop_front(&stacks->a);
	deque_push_front(&stacks->b, sta_first);
}
