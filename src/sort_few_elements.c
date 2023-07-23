/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:06:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/23 13:24:30 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2_reverse_b(t_stacks *stacks)
{
	long long	sta[2];

	sta[0] = deque_get_at(&stacks->b, 0);
	sta[1] = deque_get_at(&stacks->b, 1);
	if (sta[0] < sta[1])
		stack_sb(stacks);
}

void	sort_2(t_stacks *stacks, bool on_a)
{
	long long	sta[2];

	if (on_a)
	{
		sta[0] = deque_get_at(&stacks->a, 0);
		sta[1] = deque_get_at(&stacks->a, 1);
		if (sta[0] > sta[1])
			stack_sa(stacks);
	}
	else
	{
		sta[0] = deque_get_at(&stacks->b, 0);
		sta[1] = deque_get_at(&stacks->b, 1);
		if (sta[0] > sta[1])
			stack_sb(stacks);
	}
}

void	sort_3_a(t_stacks *stacks)
{
	long long	sta[3];
	long long	idx;

	idx = 0;
	while (idx < 3)
	{
		sta[idx] = deque_get_at(&stacks->a, idx);
		idx++;
	}
	if (sta[0] < sta[1] && sta[1] > sta[2] && sta[2] > sta[0])
	{
		stack_rra(stacks);
		stack_sa(stacks);
	}
	else if (sta[0] > sta[1] && sta[1] < sta[2] && sta[2] > sta[0])
		stack_sa(stacks);
	else if (sta[0] < sta[1] && sta[1] > sta[2] && sta[2] < sta[0])
		stack_rra(stacks);
	else if (sta[0] > sta[1] && sta[1] < sta[2] && sta[2] < sta[0])
		stack_ra(stacks);
	else if (sta[0] > sta[1] && sta[1] > sta[2] && sta[2] < sta[0])
	{
		stack_ra(stacks);
		stack_sa(stacks);
	}
}

void	sort_4_a(t_stacks *stacks)
{
	long long	pivot;
	long long	idx;

	pivot = deque_get_min_value(&stacks->a) + 1;
	idx = 0;
	while (idx < 4)
	{
		if (deque_get_at(&stacks->a, 0) > pivot)
			stack_ra(stacks);
		else
			stack_pb(stacks);
		idx++;
	}
	sort_2(stacks, true);
	sort_2_reverse_b(stacks);
	idx = 0;
	while (idx++ < 2)
		stack_pa(stacks);
}

void	sort_5_a(t_stacks *stacks)
{
	long long	pivot;
	long long	idx;

	pivot = deque_get_min_value(&stacks->a) + 1;
	idx = 0;
	while (idx < 5)
	{
		if (deque_get_at(&stacks->a, 0) > pivot)
			stack_ra(stacks);
		else
			stack_pb(stacks);
		idx++;
	}
	sort_3_a(stacks);
	sort_2_reverse_b(stacks);
	idx = 0;
	while (idx++ < 2)
		stack_pa(stacks);
}
