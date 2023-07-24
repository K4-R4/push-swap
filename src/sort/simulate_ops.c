/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/24 18:48:27 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simulate_inserting_middle(t_stacks *stacks,
		long long idx_b, long long b_front)
{
	long long	idx_a;
	long long	prev;
	long long	nex;

	idx_a = 0;
	prev = deque_get_at(&stacks->a, idx_a);
	nex = deque_get_at(&stacks->a, idx_a + 1);
	while (idx_a < stacks->a.sz - 1)
	{
		if (prev < b_front && b_front < nex)
		{
			stacks->alpha[idx_b] = convert_idx_to_ops(idx_a
					+ 1, stacks->a.sz);
		}
		idx_a++;
		prev = deque_get_at(&stacks->a, idx_a);
		nex = deque_get_at(&stacks->a, idx_a + 1);
	}
}

static void	simulate_ops_helper(t_stacks *stacks,
		long long idx_b, long long b_front)
{
	if (b_front < deque_get_at(&stacks->a, 0)
		&& b_front > deque_get_at(&stacks->a, stacks->a.sz - 1))
		stacks->alpha[idx_b] = 0;
	else if (b_front < deque_get_min_value(&stacks->a))
		stacks->alpha[idx_b] = convert_idx_to_ops(
				deque_get_min_idx(&stacks->a), stacks->a.sz);
	else
		simulate_inserting_middle(stacks, idx_b, b_front);
}

void	simulate_ops(t_stacks *stacks)
{
	long long	idx_b;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		stacks->beta[idx_b] = convert_idx_to_ops(idx_b, stacks->b.sz);
		simulate_ops_helper(stacks, idx_b, deque_get_at(&stacks->b, idx_b));
		idx_b++;
	}
}
