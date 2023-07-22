/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:56:18 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 16:55:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sa(t_stacks *stacks)
{
	long long		sta_first;
	long long		sta_second;

	if (deque_is_empty(&stacks->a) || stacks->a.sz == 1)
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "sa\n");
	sta_first = deque_pop_front(&stacks->a);
	sta_second = deque_pop_front(&stacks->a);
	deque_push_front(&stacks->a, sta_first);
	deque_push_front(&stacks->a, sta_second);
}

void	stack_sb(t_stacks *stacks)
{
	long long		sta_first;
	long long		sta_second;

	if (deque_is_empty(&stacks->b) || stacks->b.sz == 1)
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "sb\n");
	sta_first = deque_pop_front(&stacks->b);
	sta_second = deque_pop_front(&stacks->b);
	deque_push_front(&stacks->b, sta_first);
	deque_push_front(&stacks->b, sta_second);
}

void	stack_ss(t_stacks *stacks)
{
	bool	flag_print;

	flag_print = stacks->flag_print;
	stacks->flag_print = false;
	stack_sa(stacks);
	stack_sb(stacks);
	stacks->flag_print = flag_print;
	if (stacks->flag_print)
		stack_save_instr(stacks, "ss\n");
}
