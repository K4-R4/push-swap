/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:51 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/21 17:02:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simulate_a_ops(t_stacks *stacks, long long idx_b)
{
	long long	ops;
	long long	b_front;
	long long	idx_a;
	long long	prev;

	b_front = stack_get_at(stacks, 'b', idx_b);
	prev = stack_get_at(stacks, 'a', idx_a);
	while (prev < b_front)
		idx_a++;
	if (idx_a < stacks->a.sz / 2)
		ops = idx_a;
	else
		ops = idx_a - stacks->a.sz;
	stacks->alpha[idx_b] = ops;
	/*
	printf("PASSED ops %lld\n", ops);
	printf("cnt %lld\n", cnt);
	printf("sz %lld\n", stacks->a.sz);
	*/
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
			ops = idx_b - stacks->b.sz;
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
		simulate_a_ops(stacks, idx_b);
		idx_b++;
	}
}
