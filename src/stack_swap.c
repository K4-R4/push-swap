/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:56:18 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/18 22:11:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stacks *stacks, char sta)
{
	long long		sta_first;
	long long		sta_second;

	if (sta == 'a')
	{
		if (deque_is_empty(&stacks->a) || stacks->a.sz == 1)
			return ;
		if (stacks->flag_print)
			ft_printf("sa\n");
		sta_first = deque_pop_front(&stacks->a);
		sta_second = deque_pop_front(&stacks->a);
		deque_push_front(&stacks->a, sta_first);
		deque_push_front(&stacks->a, sta_second);
	}
	else
	{
		if (deque_is_empty(&stacks->b) || stacks->b.sz == 1)
			return ;
		if (stacks->flag_print)
			ft_printf("sb\n");
		sta_first = deque_pop_front(&stacks->b);
		sta_second = deque_pop_front(&stacks->b);
		deque_push_front(&stacks->b, sta_first);
		deque_push_front(&stacks->b, sta_second);
	}
}

void	stack_ss(t_stacks *stacks)
{
	stack_swap(stacks, 'a');
	stack_swap(stacks, 'b');
	if (stacks->flag_print)
		ft_printf("ss\n");
}
