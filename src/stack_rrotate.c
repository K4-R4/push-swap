/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:51:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 16:54:32 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rra(t_stacks *stacks)
{
	long long		sta_last;

	if (deque_is_empty(&stacks->a))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "rra\n");
	sta_last = deque_pop_back(&stacks->a);
	deque_push_front(&stacks->a, sta_last);
}

void	stack_rrb(t_stacks *stacks)
{
	long long		sta_last;

	if (deque_is_empty(&stacks->b))
		return ;
	if (stacks->flag_print)
		stack_save_instr(stacks, "rrb\n");
	sta_last = deque_pop_back(&stacks->b);
	deque_push_front(&stacks->b, sta_last);
}

void	stack_rrr(t_stacks *stacks)
{
	bool	flag_print;

	flag_print = stacks->flag_print;
	stacks->flag_print = false;
	stack_rra(stacks);
	stack_rrb(stacks);
	stacks->flag_print = flag_print;
	if (stacks->flag_print)
		ft_printf("rrr\n");
}
