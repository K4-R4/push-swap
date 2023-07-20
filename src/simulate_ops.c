/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/20 17:22:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	simulate_a_ops_helper(t_stacks *stacks,
			long long a_front, long long a_back, long long b_front)
{
	long long	prev;
	long long	idx_a;

	prev = a_front;
	idx_a = 1;
	while (idx_a < stacks->a.sz)
	{
	}
}

static long long		simulate_a_ops(t_stacks *stacks, long long b_front)
{
	long long	cnt;
	long long	ops;
	long long	a_front;
	long long	a_back;

	a_front = stack_get_at(stacks, 'a', 0);
	a_back = stack_get_at(stacks, 'a', stacks->a.sz - 1);
	if (b_front - 1 == a_front
		|| (b_front < a_front && a_back == stacks->a.capacity - 1))
		return (0);
	ops = simulate_a_ops_helper(stacks, a_front, a_back, b_front);
	/*
	printf("PASSED ops %lld\n", ops);
	printf("cnt %lld\n", cnt);
	printf("sz %lld\n", stacks->a.sz);
	*/
	return (ops);
}

static void	simulate_b_ops(t_stacks *stacks)
{
	long long	idx_b;
	long long	ops;

	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		if (idx_b <= stacks->b.sz / 2)
			ops = idx_b;
		else
			ops = -(stacks->b.sz - idx_b);
		stacks->beta[idx_b] = ops;
		idx_b++;
	}
}

void	simulate_ops(t_stacks *stacks)
{
	long long idx_b;

	simulate_b_ops(stacks);
	idx_b = 0;
	while (idx_b < stacks->b.sz)
	{
		stacks->alpha[idx_b] = simulate_a_ops(stacks, stack_get_at(stacks, 'b', idx_b));
		idx_b++;
	}
}
