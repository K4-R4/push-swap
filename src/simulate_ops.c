/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 01:54:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simulate_ops_helper(t_stacks *stacks, long long idx_b, long long b_front)
{
	long long	idx_a;
	long long	prev;
	long long	nex;

	if (b_front < stack_get_at(stacks, 'a', 0)
		&& stack_get_at(stacks, 'a', stacks->a.sz - 1) < b_front)
		stacks->alpha[idx_b] = 0;
	if (b_front < stack_get_min_value(stacks, 'a', stacks->a.sz))
		stacks->alpha[idx_b] = stack_get_min_idx(stacks, 'a', stacks->a.sz);
	idx_a = 1;
	prev = stack_get_at(stacks, 'a', idx_a - 1);
	nex = stack_get_at(stacks, 'a', idx_a + 1);
	while (idx_a < stacks->a.sz - 2)
	{
		if (prev < b_front && b_front < nex)
			stacks->alpha[idx_b] = idx_a;
		prev = stack_get_at(stacks, 'a', idx_a - 1);
		nex = stack_get_at(stacks, 'a', idx_a + 1);
		idx_a++;
	}
}

void	simulate_ops(t_stacks *stacks)
{
	long long	idx_b;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		stacks->beta[idx_b] = idx_b;
		simulate_ops_helper(stacks, idx_b, stack_get_at(stacks, 'b', idx_b));
		idx_b++;
	}
}
