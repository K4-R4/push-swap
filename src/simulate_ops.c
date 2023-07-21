/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/21 18:43:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simulate_ops_helper(t_stacks *stacks, long long idx_b, long long b_front)
{
	long long	ops;
	long long	idx_a;
	long long	idx_target;
	long long	nex;

	idx_a = 1;
	idx_target = 0;
	nex = stack_get_at(stacks, 'a', idx_a);
	while (idx_a < stacks->a.sz)
	{
		if (b_front < nex)
			idx_target = idx_a;
		nex = stack_get_at(stacks, 'a', ++idx_a);
	}
	if (idx_target < stacks->a.sz / 2)
		ops = idx_target;
	else
		ops = idx_target - stacks->a.sz;
	stacks->alpha[idx_b] = ops;
}

void	simulate_ops(t_stacks *stacks)
{
	long long	idx_b;
	long long	ops;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		if (idx_b <= stacks->b.sz / 2)
			ops = idx_b;
		else
			ops = idx_b - stacks->b.sz;
		stacks->beta[idx_b] = ops;
		simulate_ops_helper(stacks, idx_b, stack_get_at(stacks, 'b', idx_b));
		idx_b++;
	}
}
