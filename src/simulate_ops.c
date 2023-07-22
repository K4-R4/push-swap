/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/22 13:49:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simulate_ops_helper(t_stacks *stacks, long long idx_b, long long b_front)
{
	long long	idx_a;
	long long	prev;
	long long	nex;

	if (b_front < stack_get_at(stacks, 'a', 0)
		&& b_front > stack_get_at(stacks, 'a', stacks->a.sz - 1))
		stacks->alpha[idx_b] = 0;
	else if (b_front < stack_get_min_value(stacks, 'a', stacks->a.sz))
		stacks->alpha[idx_b] = convert_idx_to_ops(
			stack_get_min_idx(stacks, 'a', stacks->a.sz), stacks->a.sz);
	else
	{
		idx_a = 0;
		prev = stack_get_at(stacks, 'a', idx_a);
		nex = stack_get_at(stacks, 'a', idx_a + 1);
		while (idx_a < stacks->a.sz - 1)
		{
			//printf("=========%lld, %lld: %lld - %lld\n", b_front, idx_a, prev, nex);
			if (prev < b_front && b_front < nex)
			{
				//printf("PAAAAAAAAAAAASSED\n");
				stacks->alpha[idx_b] = convert_idx_to_ops(idx_a + 1, stacks->a.sz);
			}
			idx_a++;
			prev = stack_get_at(stacks, 'a', idx_a);
			nex = stack_get_at(stacks, 'a', idx_a + 1);
		}
		//printf("~~~~~%lld\n", stacks->alpha[idx_b]);
	}
}

void	simulate_ops(t_stacks *stacks)
{
	long long	idx_b;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		stacks->beta[idx_b] = convert_idx_to_ops(idx_b, stacks->b.sz);
		simulate_ops_helper(stacks, idx_b, stack_get_at(stacks, 'b', idx_b));
		idx_b++;
	}
}
