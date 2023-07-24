/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 11:14:16 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push (e - s) elements in the closed section from stack A to stack B
static void		push_b_range(t_stacks *stacks, long long pivot_small, long long pivot_large)
{
	long long	n_to_push;
	long long	sta_first;

	n_to_push = pivot_large;
	while (n_to_push)
	{
		sta_first = deque_get_at(&stacks->a, 0);
		if (0 <= sta_first && sta_first <= pivot_large - 1)
		{
			if (0 <= sta_first && sta_first <= pivot_small - 1)
			{
				stack_pb(stacks);
				stack_rb(stacks);
			}
			else
				stack_pb(stacks);
			n_to_push--;
		}
		else
			stack_ra(stacks);
	}
}

static void	prepare_sort(t_stacks *stacks)
{
	long long	pivot_small;
	long long	pivot_large;
	long long	ele;

	pivot_small = stacks->a.capacity / 3;
	pivot_large = stacks->a.capacity - pivot_small;
	push_b_range(stacks, pivot_small, pivot_large);
	while (stacks->a.sz > 5)
	{
		ele = deque_get_at(&stacks->a, 0);
		if (ele < stacks->a.capacity - 5)
			stack_pb(stacks);
		else
			stack_ra(stacks);
	}
	sort(stacks);
}

static void		optimize_instr(t_stacks *stacks)
{
	long long	len;
	char		*start;

	len = ft_strlen(stacks->instructions);
	start = ft_strnstr(stacks->instructions, "\nrb\nra", len);
	while (start)
	{
		start[1] = 'r';
		start[2] = 'r';
		ft_memmove(start + 4, start + 7, ft_strlen(start + 7) + 1);
		start = ft_strnstr(stacks->instructions, "\nrb\nra", len);
	}
}

void	sort_many(t_stacks *stacks)
{
	prepare_sort(stacks);
	execute_ops(stacks);
	optimize_instr(stacks);
}
