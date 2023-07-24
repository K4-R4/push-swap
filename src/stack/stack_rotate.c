/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:16:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 16:54:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "stack.h"

void	stack_ra(t_stacks *stacks)
{
	long long		sta_first;

	if (deque_is_empty(&stacks->a))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "ra\n");
	sta_first = deque_pop_front(&stacks->a);
	deque_push_back(&stacks->a, sta_first);
}

void	stack_rb(t_stacks *stacks)
{
	long long		sta_first;

	if (deque_is_empty(&stacks->b))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "rb\n");
	sta_first = deque_pop_front(&stacks->b);
	deque_push_back(&stacks->b, sta_first);
}

void	stack_rr(t_stacks *stacks)
{
	bool	flag_print;

	flag_print = stacks->flag_print;
	stacks->flag_print = false;
	stack_ra(stacks);
	stack_rb(stacks);
	stacks->flag_print = flag_print;
	if (stacks->flag_print)
		stack_save_instr(stacks, "rr\n");
}
